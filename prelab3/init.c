/**
* @file init.c
* @brief 
*
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

int main()
{
        int numbers[1000];

        int i;
        for (i = 1; i < 1001; i++)
        {
                numbers[i] = i;
                printf("%d\n", numbers[i]);
        }

        return 0;
}
