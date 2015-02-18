/**
* @file divisor.c
* @brief Checks if an array of numbers is divisible by a number 
* 
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

void array_mod(int a[], int b[], size_t size, int divisor);

int main()
{
        int a[10] = {13, 44, 85, 23, 72, 99, 100, 108, 222, 1084};
        int b[10];

        array_mod(a, b, 10, 4);

        int i;
        for (i = 0; i < 10; i++)
        {
                printf("%d\t%d\n", a[i], b[i]);
        }

        return 0;
}

/**
* Mods an array
* @param a An array with the values to mod
* @param b An array to store the results
* @param size The size of the arrays
* @param divisor the number to mod by
*/
void array_mod(int a[], int b[], size_t size, int divisor)
{
        int i;
        for (i = 0; i < size; i++)
        {
                b[i] = a[i] % divisor == 0 ? 1 : 0;
        }
}
