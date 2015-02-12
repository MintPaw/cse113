#include<stdio.h>

float f_to_c(float f);
void print_f_to_c(float fahr);

int main()
{
	float fahr = 212;
	printf("Give a Fahrenheit temperature: ");
	scanf("%f", &fahr);
	print_f_to_c(fahr);
	
	return 0;
}
/**
* Converts Fahrenheit to degrees Celsius
* @param fahr The temperature in Fahrenheit
* @return The temperature in Celsius
*/
float f_to_c(float fahr)
{
	return (fahr - 32) * 5.0 / 9.0;
}

/**
* Prints a Fahrenheit to Celsius conversion
* @param fahr The temperature in Fahrenheit
*/

void print_f_to_c(float fahr)
{
	printf("%.2f f is %.2f c\n", fahr, f_to_c(fahr));
}
