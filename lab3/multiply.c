/**
* @file multiply.c
* @brief Multiplies a range of numbers
* 
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

int multiply_range(int start, int end);

int main()
{
        printf("%d\n", multiply_range(1, 5));
        printf("%d\n", multiply_range(5, 1));
        printf("%d\n", multiply_range(5, 5));

        return 0;
}

int multiply_range(int start, int end)
{
        if (start > end)
        {
                int t = end;
                end = start;
                start = t;
        }        

        int result = 1;
        int i;

        for (i = start; i < end + 1; i++)
        {
                result *= i;
        }

        return result;
}
