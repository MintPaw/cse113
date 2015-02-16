/**
* @file init.c
* @brief Prints out numbers using a for loop in a function
*
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

void print_array(int a[], int length);

int main()
{
        int numbers[1000];

        int i;
        for (i = 1; i < 1001; i++)
        {
                numbers[i] = i;
        }

        print_array(numbers, sizeof(numbers) / sizeof(numbers[0]));

        return 0;
}

/**
* Prints an array of integers
* @param a An array of integers
* @param length The length of the array
*/
void print_array(int a[], int length)
{
        int i;
        for (i = 0; i < length + 1; i++)
        {
                printf("%d\n", a[i]);
        }
}
