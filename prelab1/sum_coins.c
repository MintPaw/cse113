#include<stdio.h>

int sum_coins(int pennies, int nickles, int dimes, int quarters);

int main()
{
        printf("1 penny, 2 nickels, 3 dimes, 4 quarters; %d\n", sum_coins(1, 2, 3, 4));
        printf("13 penny, 7 nickels, 18 dimes, 27 quarters; %d\n", sum_coins(13, 7, 18, 27));
        return 0;
}

int sum_coins(int pennies, int nickles, int dimes, int quarters)
{
        return pennies + nickles * 5 + dimes * 10 + quarters * 25;
}
