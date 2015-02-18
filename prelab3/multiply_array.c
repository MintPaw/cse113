/**
* @file multiply_array.c
* @brief Multiplies a range of numbers given by an array
* 
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

int multiply_range(int a[], size_t size, int start, int end);

int main()
{
        int a[7] = {6, 3, 5, 2, 3, 2, 4};

        printf("%d\n", multiply_range(a, sizeof(a) / sizeof(a[0]), 1, 4));

        return 0;
}

/**
* Multiplies a segment of an array
* @param a The array with the values to multiply
* @param size The size of the array
* @param start the start of the segment to multiply
* @param end the end of the segment to multiply
* @return The result of the multiplication
*/
int multiply_range(int a[], size_t size, int start, int end)
{
        if (start > end)
        {
                int t = end;
                end = start;
                start = t;
        }

        if (start < 0)
        {
                start = 0;
        }

        if (end > size)
        {
                end = size;
        }

        int result = 1;
        int i;

        for (i = start; i < end + 1; i++)
        {
                result *= a[i];
        }

        return result;
}
