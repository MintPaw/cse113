/**
* @file ch5_ex1.c
* @brief Figures the number of digits in a number
*
* @author Jeru Sanders
* @date 2/13/15
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input_string[5];
	int input_int;

	printf("Give an integer: ");
	fgets(input_string, 5, stdin);
	input_int = atoi(input_string);

	printf("\nThe number has ");
	if (input_int >= 1000)
	{
		printf(">= 4");
	} else if (input_int >= 100) {
		printf("3");
	} else if (input_int >= 10) {
		printf("2");
	} else if (input_int >= 1) {
		printf("1");
	}
	printf(" digits\n");

	return 0;
}
