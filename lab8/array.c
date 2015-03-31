#include <stdio.h>
#include <stdlib.h>

void print_array(int a[], size_t len)
{
	int i = 0;

	for( ;i < len;i++)
		printf(i == len - 1 ? "%d\n" : "%d ", *(a + i));
			
}

/* pointer arthimetic version of print_array */
/* void print_parray(int *a, size_t len) */
/* { */

			
/* } */


void inc_array(int a[], size_t len)
{
	int i = 0;
 
	for( ; i < len; i++)
		*(a + i) += 1; 
		
}

/* pointer based version */
/* void inc_parray(int *a, size_t len) */
/* { */
/* 	int *p = a; */

/* } */


/* a = a + b */
void add_arrays(int *a, int *b, size_t len)
{
	int i = 0;
	
	for(; i < len; i++) 
		*(a + i) += *(b + i);
	
}

/* pointer version of add_arrays a = a + b */
/* void add_arrays(int *a, int *b, size_t len) */
/* { */
	
/* } */


int main() 
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	size_t len_a = sizeof(a)/sizeof(int);
	size_t len_b = sizeof(b)/sizeof(int);
	
	printf("a = ");
	print_array(a, len_a);
	/* print_parray(a, len_a); */

	printf("\nb = ");
	print_array(b, len_b);
	/* print_parray(b, len_b); */

	inc_array(a, len_a);
	printf("\nafter incrementing\na = ");
	print_array(a, len_a);
	/* inc_parray(a, len_a) */
	/* print_parray(a, len_a); */

	if (len_a != len_b) 	/* assume arrays are of the same length */
		exit(EXIT_FAILURE);
	else
		add_arrays(a, b, len_a);
		/* add_parrays(a, b, len); */
	
	printf("\na = a + b\na = ");
	print_array(a, len_a);
	/* print_parray(a, len_a); */
	printf("\nb remains unchanged\nb = ");
	print_array(b, len_b);
	/* print_parray(b, len_b); */

	return 0;
}
