#include <stdio.h>

void print_even_odd(int i);
void print_if_15(int i);
void print_if_div_7(int i);

int is_even(int i);
int is_15(int i);
int is_div_7(int i);

void main()
{
	int i;
	for (i = 0; i <= 10; i++) {
		print_even_odd(i);
	}

	for (i = 11; i <= 20; i++) {
		print_if_15(i);
	}

	for (i = 20; i <= 30; i++) {
		print_if_div_7(i);
	}

}

void print_even_odd(int i)
{	
	if (is_even(i)) {
		printf("--------------------------------------------------    [%d]\n", i);
	} else {		
		printf("   +++++++++++++++++++++++++++++++++++++++++++        [%d]\n", i);
	}
}

void print_if_15(int i)
{
	if (is_15(i)) {
		printf("       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^           [%d]\n", i);
	}
}

void print_if_div_7(int i)
{
	if (is_div_7(i)) {
		printf("            **************************                [%d]\n", i);
	}
}

int is_even(int i)
{
	return !(i % 2);
}

int is_15(int i)
{
	return i == 15;
}

int is_div_7(int i)
{
	return !(i % 7);
}
