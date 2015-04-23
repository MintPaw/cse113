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
* Prints out information about a node
* @param node The node to get info on
*/
void print_node(struct bit_t *node)
{
	printf("n = %d\tprev = %p\tnext = %p\tloc = %p\n"
		, node->n, node->prev, node->next, node);
}

/**
* Prints out the value of the nude
* @param node The node to get the value on
*/
void print_node_neat(struct bit_t *node)
{
	printf("%d", node->n);
}

/**
* Call print_node on every node in a list
* @param head The head node of hte list
*/
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

/**
* Call print_node_neat on every node in a list
* @param head The head node of hte list
*/
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

/**
* Creates an empty bit list
* @param size The word size
* @return The head of the list
*/
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

/**
* Preforms the add function on the cpu
* @param cpu The cpu to preform the action on
*/
void add(struct cpu_t *cpu)
{
	cpu->carry = add_registers(cpu->r1_head,
							   cpu->r2_head,
							   cpu->r3_head,
							   cpu->word_size) > 0;

	set_flags(cpu);
}

/**
* Preforms the subtract function on the cpu
* @param cpu The cpu to preform the action on
*/
void subtract(struct cpu_t *cpu)
{
	complement_r2(cpu);
	add(cpu);
}

/**
* Preforms the and function on the cpu
* @param cpu The cpu to preform the action on
*/
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

/**
* Preforms the or function on the cpu
* @param cpu The cpu to preform the action on
*/
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

/**
* Preforms the xor function on the cpu
* @param cpu The cpu to preform the action on
*/
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

/**
* Gets a value in a linked list by index
* @param head The head of the list
* @param index The index to get
* @return The value of the node
*/
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

/**
* Sets a value in a linked list by index
* @param head The head of the list
* @param index The index to get
* @param value The value to assign the the node
*/
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

/**
* Sets the flags on the cpu
* @param cpu The cpu to set flags on
*/
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

	if (cpu->r1_head->n == 0 &&
		cpu->r2_head->n == 0 &&
		cpu->r3_head->n == 1)
	{
		cpu->overflow = 1;
	} else if (cpu->r1_head->n == 1 &&
			   cpu->r2_head->n == 1 &&
			   cpu->r3_head->n == 0)
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


/**
* Prints out the flags
* @param cpu The cpu to get flags from
*/
void print_flags(struct cpu_t *cpu)
{
	printf("flags:\noverflow: %d\ncarry: %d\nsign: %d\nparity: %d\nzero: %d\n",
		cpu->overflow, cpu->carry, cpu->sign, cpu->parity, cpu->zero);
}

/**
* Converts the value in r2 to it's complement
* @param cpu The cpu to preform the action on
*/
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

/**
* Adds together two registers
* @param head1 The first register to add
* @param head2 The second register to add
* @param head3 The register to store the value in
* @param size The word size
* @return The value of the carry bit
*/
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

/**
* Clones a list
* @param head The head of the list to clone
* @return The head of the new list
*/
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

/**
* Prints X dashes in a row
* @param size How many dashes to print
*/
void print_dashes(int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("-");
	}
	printf("\n\n");
}

/**
* Converts a list of bit_t's to an int
* @param head The head of the list to convert
* @param unsign If the value is unsigned
* @return The integer representation
*/
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
		dec = ~dec;
	}

	return dec;
}