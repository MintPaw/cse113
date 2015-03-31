/**
* @file multiples.c
* @brief Finds all the multiples of 3 and 5 under 1000
* 
* @author Jeru Sanders
* @date 03/09/2015
*/

#include<stdio.h>

int main()
{
        int i; 
        for (i = 0; i < 1000; i++)
        {
                if (i % 3 == 0 && i % 5 == 0)
                {
                        printf("%d\n", i); /* printf("FizzBuzz!\n"); */
                }
        }

        return 0;
}
