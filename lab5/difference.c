/**
* @file difference.c
* @brief Find (1^2 + 2^2 + 3^2 + ... + 100^2) - (1 + 2 + 3 + ... + 100)^2
* 
* @author Jeru Sanders
* @date 03/09/2015
*/

#include<stdio.h>

int main()
{
        int first_sum = 0;
        int second_sum = 0;
        int difference;
        
        int i; 
        for (i = 1; i < 101; i++)
        {
                first_sum += i * i;
                second_sum += i;
        }

        second_sum = second_sum * second_sum;
        difference = second_sum - first_sum;

        printf("It's %d\n", difference);

        return 0;
}
