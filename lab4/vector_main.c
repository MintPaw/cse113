#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "vector.h"
#include "string.h"

#define copy_array memcpy

void print_array(int array[], int size);

int main(void)
{
        srandom(time(NULL));

        int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 3 };
        int a2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 3 };
        int a3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 3 };
        int b3[10];
        int a4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 3 };
        int b4[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
        int c4[10];
        int c5[10];
        int a6[] = { 1, 2, 3, 4, 5 };
        int b6[] = { 6, 7, 8, 9, 10 };
        int c6[5];
        int a7[10];
        int size_10int = sizeof(a1) / sizeof(a1[0]);
        int size_5int = sizeof(a6) / sizeof(a6[0]);

        printf("Start:\n");
        print_array(a1, size_10int);

        printf("\nMultiply by 5:\n");
        multiply_array(a1, size_10int, 5);
        print_array(a1, size_10int);

        printf("\nAdd 3:\n");
        add_array(a2, size_10int, 3);
        print_array(a2, size_10int);

        printf("\nBefore copy:\n");
        print_array(a3, size_10int);
        print_array(b3, size_10int);
        printf("After copy:\n");
        copy_array(b3, a3, sizeof(a3));
        print_array(a3, size_10int);
        print_array(b3, size_10int);

        printf("\nSumming arrays:\n");
        print_array(a4, size_10int);
        print_array(b4, size_10int);
        add_arrays(a4, b4, c4, size_10int);
        printf("Result:\n");
        print_array(c4, size_10int);

        printf("\nMultiplying arrays:\n");
        print_array(a4, size_10int);
        print_array(b4, size_10int);
        multiply_arrays(a4, b4, c5, size_10int);
        printf("Result:\n");
        print_array(c5, size_10int);

        printf("\nInsvese multiplying arrays:\n");
        print_array(a6, size_5int);
        print_array(b6, size_5int);
        inversemul_arrays(a6, b6, c6, size_5int);
        printf("Result:\n");
        print_array(c6, size_5int);

        printf("\nRandom array:\n");
        generate_array(a7, 50);
        print_array(a7, size_10int);

        return 0;
}

/**
* Prints out an array
* @param array The array to print
* @param size The size of the array
*/
void print_array(int array[], int size)
{
        printf("[");

        int i;
        for (i = 0; i < size; i++)
        {
                printf("%d", array[i]);
                if (i < size - 1)
                {
                        printf(", ");
                }
        }
        printf("]\n");
}
