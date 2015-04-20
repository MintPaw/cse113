#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

/**
* Gets a real character, filters things we don't want, also case insensitive
* @param c A pointer to a character to store the input
*/
void get_real_char(char *c)
{
	char temp;
	while((temp = tolower(getchar())) != '\n')
	{
		*c = temp;
	}
}

/**
* Converts a string into a double linked list of bit_t's
* @param string_temp The binary string you would like to convert.
* @param size The word size for 0 padding
* @return The head of the bit_t list
*/
struct bit_t *string_to_bit_list(char *string_temp, int size)
{
	struct bit_t *head = malloc(sizeof(struct bit_t));
	struct bit_t *prev_node = NULL;
	struct bit_t *current_node = head;
	char string[256] = "";

	while (strlen(string) < 
		size - strlen(string_temp))
	{
		strcat(string, "0");
	}

	strcat(string, string_temp);

	int i;
	for (i = 0; i < size; i++)
	{
		if (i)
		{
			prev_node = current_node;
			current_node->next = malloc(sizeof(struct bit_t));
			current_node = current_node->next;
		}

		current_node->prev = prev_node;
		current_node->next = NULL;
		if (string[i] == '0') current_node->n = 0;
		if (string[i] == '1') current_node->n = 1;
	}

	return head;
}

/**
* Returns the tail of a bit_t list
* @param head The head of the list
* @return The tail node of the list
*/
struct bit_t *get_tail(struct bit_t *head)
{
	struct bit_t *current_node = head;

	for (;;)
	{
		if (current_node->next)
		{
			current_node = current_node->next;
		} else {
			return current_node;
		}
	}
}

/**
* --------------------------------------------------------------------
*/
void print_node(struct bit_t *node)
{
	printf("n = %d\tprev = %p\tnext = %p\tloc = %p\n"
		, node->n, node->prev, node->next, node);
}

void print_node_neat(struct bit_t *node)
{
	printf("%d", node->n);
}

void print_register(struct bit_t *head)
{
	struct bit_t *current_node = head;

	for (;;)
	{
		print_node(current_node);
		if (current_node->next)
		{
			current_node = current_node->next;
		} else {
			return;
		}
	}
}

void print_register_neat(struct bit_t *head)
{
	struct bit_t *current_node = head;

	for (;;)
	{
		print_node_neat(current_node);
		if (current_node->next)
		{
			current_node = current_node->next;
		} else {
			printf("\n");
			return;
		}
	}
}

struct bit_t *empty_bit_list(int size)
{
	char string[128];

	int i;
	for (i = 0; i < size; i++)
	{
		strcat(string, "0");
	}

	return string_to_bit_list(string, size);
}

void add(struct cpu_t *cpu)
{
	cpu->carry = add_registers(cpu->r1_head,
							   cpu->r2_head,
							   cpu->r3_head,
							   cpu->word_size) > 0;

	set_flags(cpu);
}

void subtract(struct cpu_t *cpu)
{
	complement_r2(cpu);
	add(cpu);
}

void and(struct cpu_t *cpu)
{
	int i;
	for (i = 0; i < cpu->word_size; i++)
	{
		set_value(
				cpu->r3_head,
				i,
				get_value(cpu->r1_head, i) &&
				get_value(cpu->r2_head, i));
	}

	set_flags(cpu);
	cpu->overflow = 0;
	cpu->carry = 0;
}

void or(struct cpu_t *cpu)
{
	int i;
	for (i = 0; i < cpu->word_size; i++)
	{
		set_value(
				cpu->r3_head,
				i,
				get_value(cpu->r1_head, i) ||
				get_value(cpu->r2_head, i));
	}

	set_flags(cpu);
	cpu->overflow = 0;
	cpu->carry = 0;
}

void xor(struct cpu_t *cpu)
{
	int i;
	for (i = 0; i < cpu->word_size; i++)
	{
		set_value(
				cpu->r3_head,
				i,
				get_value(cpu->r1_head, i) ^
				get_value(cpu->r2_head, i));
	}

	set_flags(cpu);
	cpu->overflow = 0;
	cpu->carry = 0;
}

char get_value(struct bit_t *head, int index)
{
	struct bit_t *current_node = head;

	int i;
	for (i = 0; i < index; i++)
	{
		current_node = current_node->next;
	}

	return current_node->n;
}

void set_value(struct bit_t *head, int index, char value)
{
	struct bit_t *current_node = head;

	int i;
	for (i = 0; i < index; i++)
	{
		current_node = current_node->next;
	}

	current_node->n = value;
}

void set_flags(struct cpu_t *cpu)
{
	int ones = 0;
	int i;

	for (i = 0; i < cpu->word_size; i++)
	{
		if (get_value(cpu->r3_head, i) == 1)
		{
			ones++;
		}
	}

	if (cpu->r1_head.n == 0 &&
		cpu->r2_head.n == 0 &&
		cpu->r3_head.n == 1)
	{
		cpu->overflow = 1;
	} else if (cpu->r1_head.n == 1 &&
			   cpu->r2_head.n == 1 &&
			   cpu->r3_head.n == 0)
	{
		cpu->overflow = 1;
	} else {
		cpu->overflow = 0;
	}

	cpu->zero = ones == 0;
	cpu->parity = !(ones % 2);
	cpu->sign = get_value(cpu->r3_head, 0);
	cpu->carry = cpu->carry > 0;
}

void print_flags(struct cpu_t *cpu)
{
	printf("flags:\noverflow: %d\ncarry: %d\nsign: %d\nparity: %d\nzero: %d\n",
		cpu->overflow, cpu->carry, cpu->sign, cpu->parity, cpu->zero);
}

void complement_r2(struct cpu_t *cpu)
{
	struct bit_t *current_node = cpu->r2_head;

	for (;;)
	{
		if (!current_node) break;
		current_node->n = !current_node->n;
		current_node = current_node->next;
	}

	struct bit_t *one = string_to_bit_list("1", cpu->word_size);
	struct bit_t *comp = empty_bit_list(cpu->word_size);

	add_registers(cpu->r2_head, one, comp, cpu->word_size);
	cpu->r2_head = comp;
	add(cpu);
}

int add_registers(struct bit_t *head1,
				  struct bit_t *head2,
				  struct bit_t *head3,
				  int size)
{
	int result;
	int i;
	int carry = 0;
	for (i = size - 1; i >= 0; i--)
	{
		result = get_value(head1, i) + 
				 get_value(head2, i) + 
				 carry;

		if (result > 1)
		{
			if (result % 2)
			{
				result = 1;
			} else {
				result = 0;
			}

			carry = 1;
		} else {
			carry = 0;
		}

		set_value(head3, i, result);
	}

	return carry;
}

struct bit_t *clone_list(struct bit_t *head)
{
	struct bit_t *clone_head = malloc(sizeof(struct bit_t));
	struct bit_t *current_main = head;
	struct bit_t *current_clone = clone_head;

	for (;;)
	{
		current_clone->n = current_main->n;

		if (!current_main->next)
		{
			return clone_head;
		}
		current_clone->next = malloc(sizeof(struct bit_t));

		current_main = current_main->next;
		current_clone = current_clone->next;
	}
}

void print_dashes(int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("-");
	}
	printf("\n\n");
}

int register_to_int(struct bit_t *head, char unsign)
{
	struct bit_t *current_node = head;
	char str[256] = "";
	int dec = 0;
	char comp = 0;

	if (!unsign && current_node->n == 1)
	{
		comp = 1;
	}

	for (;;)
	{
		if (current_node == NULL) break;

		if (current_node->n == 0)
		{
			strcat(str, "0");
		} else if (current_node->n == 1) {
			strcat(str, "1");
		}

		current_node = current_node->next;
	}

	dec = (int)strtol(str, NULL, 2);

	if (comp)
	{
		printf("Comping");
		dec = ~dec;
	}

	return dec;
}