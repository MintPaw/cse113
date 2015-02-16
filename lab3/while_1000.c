/*
* @file while_1000.c
* @brief Uses a while loop to print out numbers
* 
* @author Jeru Sanders
* @date 2/16/2015
*/

#include<stdio.h>

int main()
{
        int i = 1;
        
        while(i < 1001)
        {
                printf("%d\t", i);
                i++;
        }
        
        printf("\n");
        return 0;
}
