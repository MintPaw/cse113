#include<stdio.h>

float evaluate_expression(float n);

int main()
{
        printf("When n=0; %lf\n", evaluate_expression(0)); 
        printf("When n=1; %lf\n", evaluate_expression(1)); 
        printf("When n=5; %lf\n", evaluate_expression(5)); 
        printf("When n=10; %lf\n", evaluate_expression(10)); 
}

float evaluate_expression(float n)
{
        return n/3 + 2/3;
}
