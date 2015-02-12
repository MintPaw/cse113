#include<stdio.h>

float euros_to_dollars(float euros);
float dollars_to_euros(float dollars);

int main()
{
        printf("10$; %lf\n", dollars_to_euros(10));
        printf("100.25$; %lf\n", dollars_to_euros(100.25));
        printf(".75 euro; %lf\n", euros_to_dollars(.75));
        printf("10 euro; %lf\n", euros_to_dollars(10));
        printf("100.25 euro; %lf\n", euros_to_dollars(100.25));
        return 0;
}

float euros_to_dollars(float euros)
{
        return euros / .75;
}


float dollars_to_euros(float dollars)
{
        return dollars * .75;
}
