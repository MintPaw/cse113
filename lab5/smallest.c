/**
* @file smallest.c
* @brief Finds the smallest number that can be divided by the number 1-20 evenly
* 
* @author Jeru Sanders
* @date 03/09/2015
*/

#include<stdio.h>

int main()
{
        int i; 

        for (i = 1;; i++)
        {
                char failed = 0;
                int j;
                for (j = 1; j < 21; j++)
                {
                        if (i % j != 0)
                        {
                                failed = 1;
                        }
                }

                if (!failed)
                {
                        printf("It's %d\n", i);
                        return 0;
                }
        }

        return 0;
}
