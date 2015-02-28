/**
* @lab4_q2 .c
* @brief Creates enum values for colours automatically
* 
* @author Jeru Sanders
* @date 2/27/2015
*/

#include<stdio.h>

enum colour
{
        RED = 18, 
        ORANGE,
        YELLOW = 5, 
        GREEN, BLUE, 
        INDIGO = 14, 
        VIOLET
};

int main()
{
        printf("RED = %d\n", RED);
        printf("ORANGE = %d\n", ORANGE);
        printf("YELLOW = %d\n", YELLOW);
        printf("GREEN = %d\n", GREEN);
        printf("BLUE = %d\n", BLUE);
        printf("INDIGO = %d\n", INDIGO);
        printf("VIOLET = %d\n", VIOLET);
        return 0;
}
