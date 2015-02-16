/**
* @file ch5_ex11.c
* @brief Converts two digit numbers into a string
*
* @author Jeru Sanders
* @date 2/13/15
*/

#include<stdio.h>

int main()
{
	char string_input[4];
	char digit0;
	char digit1;

	printf("Give a two digit number: ");
	fgets(string_input, 4, stdin); 

	digit0 = string_input[0];
	digit1 = string_input[1];
	if (digit0 == '1')
	{
		if (digit1 == '1')
		{
			printf("eleven");
		} else if (digit1 == '2') {
			printf("twelve");
		} else if (digit1 == '3') {
			printf("thirteen");
		} else if (digit1 == '4') {
			printf("fourteen");
		} else if (digit1 == '5') {
			printf("fifteen");
		} else if (digit1 == '6') {
			printf("sixteen");
		} else if (digit1 == '7') {
			printf("seventeen");
		} else if (digit1 == '8') {
			printf("eighteen");
		} else if (digit1 == '9') {
			printf("ninteeen");
		}
	} else {
		if (digit0 == '2')
		{
			printf("twenty-");
		} else if (digit0 == '3') {
			printf("thirty-");
		} else if (digit0 == '4') {
			printf("foury-");
		} else if (digit0 == '5') {
			printf("fifty-"); /* Yes this is probably spelled wrong, I dunno */
		} else if (digit0 == '6') {
			printf("sixty-");
		} else if (digit0 == '7') {
			printf("seventy-");
		} else if (digit0 == '8') {
			printf("eighty-");
		} else if (digit0 == '9') {
			printf("ninty-");
		}

		if (digit1 == '1')
		{
			printf("one");
		} else if (digit1 == '2') {
			printf("two");
		} else if (digit1 == '3') {
			printf("three");
		} else if (digit1 == '4') {
			printf("four");
		} else if (digit1 == '5') {
			printf("five");
		} else if (digit1 == '6') {
			printf("six");
		} else if (digit1 == '7') {
			printf("seven");
		} else if (digit1 == '8') {
			printf("eight");
		} else if (digit1 == '9') {
			printf("nine");
		}
	}


	printf("\n");
	return 0;
}
