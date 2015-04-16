#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary.h"

int main()
{
	struct cpu_t cpu;

	char input_string[66];
	char input_char;

	printf("Give word size: ");
	fgets(input_string, 66, stdin);

	cpu.word_size = atoi(input_string);

	printf("Unsigned [y/N]: ");
	get_real_char(&input_char);
	cpu.unsign = input_char == 'y';

	printf("Give expression: ");
	fgets(input_string, 66, stdin);
	cpu.unsign = input_char == 'y';

	char *bin_string_1;
	char *bin_string_2;
	char *op;

	bin_string_1 = strtok(input_string, " ");
	op = strtok(NULL, " ");
	bin_string_2 = strtok(NULL, " \n");

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
	print_register_neat(cpu.r2_head);
	print_register_neat(cpu.r3_head);
	print_flags(&cpu);

	return 0;
}