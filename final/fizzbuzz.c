/**
* @file fizzbuzz.c
* @brief Does fizzbuzz
* @details Prints Fizz and Buzz depending on the multiplicity of numbers 1-n
* @author Jeru Sanders
* @date 5/7/15
* @todo None
* @bug None
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	int i;
	char need_newline;
	for (i = 1; i < n + 1; i++) {
		need_newline = 0;

		printf("%d\n", i);
		if (!(i % 3)) {
			printf("Fizz");
			need_newline = 1;
		}
		if (!(i % 5)) {
			printf("Buzz");
			need_newline = 1;
		}

		if (need_newline) {
			printf("\n");
		}
	}
	return 0;
}