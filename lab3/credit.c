/**
 * @file credit.c
 * @author
 * @date
 * @brief determine if a credit card is valid using Luhn's algorithm.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DIGITS 16
#define VALID 0
#define INVALID -1

void convert_card(int card[], char num[], int num_digits);
void print_card(int card[], int size);

int main(void)
{
	int card[NUM_DIGITS];
	char visa[] = "4012888888881881"; /* valid card */
	/* char visa[] = "4012888888881882"; */ /*invalid card */
	convert_card(card, visa, NUM_DIGITS);
	print_card(card, NUM_DIGITS);
		
	return 0;

}

void convert_card(int card[], char num[], int num_digits)
{
	int i;

	for(i = 0; i < num_digits; i++) 		
		card[i] = num[i] - '0';
	
}


void print_card(int card[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("card[%d] = %d\n", i, card[i]);
}

