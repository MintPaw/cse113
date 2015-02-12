#include<stdio.h>

float c_to_f(float c);
void print_c_to_f(float cel);

int main()
{
	float cel = 100;
	printf("Give a Calsius temperature: ");
	scanf("%f", &cel);
	print_c_to_f(cel);
	
	return 0;
}
/**
* Converts Celsius to degrees Farhenheit
* @param fahr The temperature in Celsius
* @return The temperature in Farenheit
*/
float c_to_f(float cel)
{
	return cel * 9 / 5 + 32;
}

/**
* Prints a Celsius to Fahrenheit conversion
* @param cel The temperature in Celsius
*/

void print_c_to_f(float cel)
{
	printf("%.2f c is %.2f f\n", cel, c_to_f(cel));
}
