#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary.h"

void get_real_char(char *c);

struct bit_t
{
	unsigned char n;
	struct bit_t *prev;
	struct bit_t *next;
};

struct cpu_t
{
	int word_size;
	int unsign; //0 -- signed ,1 for unsigned
	// flags
	int overflow;
	int carry;
	int sign;
	int parity;
	int zero;
	struct bit_t * r1_head;
	struct bit_t * r1_tail;
	struct bit_t * r2_head;
	struct bit_t * r2_tail;
	struct bit_t * r3_head;
	struct bit_t * r3_tail;
};

int main()
{
	struct cpu_t cpu;

	char input_string[64];
	char input_char;

	printf("Give word size: ");
	fgets(input_string, 64, stdin);

	// TODO(jeru): Error check all input_string
	cpu.word_size = atoi(input_string);

	printf("Unsigned [y/N]: ");
	get_real_char(&input_char);
	// TODO(jeru): String equality
	cpu.unsign = input_char == 'y';

	printf("Give expression: ");
	fgets(input_string, 64, stdin);
	cpu.unsign = input_char == 'y';

	char *bin_string_0;
	char *bin_string_1;
	char *op;

	bin_string_0 = strtok(input_string, "-");
	op = strtok(NULL, "-");
	bin_string_1 = strtok(NULL, "-");

	return 0;
}

/**
* Gets a real character, filters things we don't want, also case insensitive
* @param c A pointer to a character to store the input
*/
void get_real_char(char *c)
{
        printf("Make a selection: ");

        char temp;
        while((temp = tolower(getchar())) != '\n')
        {
                *c = temp;
        }
}
