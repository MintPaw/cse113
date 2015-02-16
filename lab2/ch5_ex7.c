/**
* @file ch5_ex7.c
* @brief Prints the largest and smallers of given integers
*
* @author Jeru Sanders
* @date 2/13/15
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input_string[64];
	int input_numbers[4];

	printf("Give 4 integers sperated by spaces: ");
	fgets(input_string, 64, stdin);
	sscanf(input_string, "%i %i %i %i", &input_numbers[0], &input_numbers[1], &input_numbers[2], &input_numbers[3]);
	
	int lowest = input_numbers[0];
	int highest = input_numbers[0];
	
	int i;
	for (i = 0; i < 4; i++)
	{
		if (input_numbers[i] < lowest) 
		{
			lowest = input_numbers[i];
		}

		if (input_numbers[i] > highest) 
		{
			highest = input_numbers[i];
		}
	}

	printf("Lowest: %i\nHighest:%i\n", lowest, highest);

	return 0;	
}
