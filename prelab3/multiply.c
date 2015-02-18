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
        printf("%d, %d = %d\n", 3, 7, multiply_range(3, 7));
        printf("%d, %d = %d\n", 19, 18, multiply_range(19, 18));

        return 0;
}

/**
* Multiplies a range of numbers
* @param start The start of the range
* @param end The end of the range
* @return the result of the multiplication
*/
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
