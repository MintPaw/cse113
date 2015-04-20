#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary.h"

int main()
{
	struct cpu_t cpu;

	char input_string[128];
	char input_char;

word_size:
	printf("Give word size: ");
	fgets(input_string, 128, stdin);
	cpu.word_size = atoi(input_string);

	if (cpu.word_size > 64 && cpu.word_size < 1)
	{
		goto word_size;
		printf("Word size must be between 1 and 64 bits\n");
	}

	printf("Unsigned [y/N]: ");
	get_real_char(&input_char);
	cpu.unsign = input_char == 'y';

expression:
	printf("Give expression: ");
	fgets(input_string, 128, stdin);
	cpu.unsign = input_char == 'y';

	int i;
	for (i = 0; i < strlen(input_string); i++)
	{
		if (
			input_string[i] != '0' &&
			input_string[i] != '1' &&
			input_string[i] != '+' &&
			input_string[i] != '-' &&
			input_string[i] != '&' &&
			input_string[i] != '|' &&
			input_string[i] != '^' &&
			input_string[i] != ' ' &&
			input_string[i] != '\n')
		{
			printf("Bad expression, error at char: %d\n", i);
			goto expression;
		}
	}

	char *bin_string_1;
	char *bin_string_2;
	char *op;

	bin_string_1 = strtok(input_string, " ");
	op = strtok(NULL, " ");
	bin_string_2 = strtok(NULL, " \n");

	if (strlen(bin_string_1) > cpu.word_size)
	{
		printf("Bad expression, error at expression 1\n");
		goto expression;
	} else if (strlen(bin_string_2) > cpu.word_size) {
		printf("Bad expression, error at expression 2\n");
		goto expression;
	} else if (strlen(op) != 1) {
		printf("Bad expression, error at operation\n");
		goto expression;
	}

	cpu.r1_head = string_to_bit_list(bin_string_1, cpu.word_size);
	cpu.r2_head = string_to_bit_list(bin_string_2, cpu.word_size);
	cpu.r3_head = empty_bit_list(cpu.word_size);
	cpu.r1_tail = get_tail(cpu.r1_head);
	cpu.r2_tail = get_tail(cpu.r2_head);
	cpu.r3_tail = get_tail(cpu.r3_head);

	if (*op == '+')
	{
		add(&cpu);
	} else if (*op == '-') {
		subtract(&cpu);
	} else if (*op == '&') {
		and(&cpu);
	} else if (*op == '|') {
		or(&cpu);
	} else if (*op == '^') {
		xor(&cpu);
	}

	printf("Result:\n");
	print_register_neat(cpu.r1_head);
	printf("%s\n", op);
	print_register_neat(cpu.r2_head);
	print_dashes(cpu.word_size);
	print_register_neat(cpu.r3_head);
	printf("%sdecimal: %d\n",
		cpu.unsign ? "" : "singed ",
		register_to_int(cpu.r3_head, cpu.unsign));
	print_flags(&cpu);

	printf("\n\n");
	printf("Again? [Y/n]: ");
	get_real_char(&input_char);
	if (input_char == 'n') return 0;

	printf("\n\n");
	goto(word_size);

	return 0;
}