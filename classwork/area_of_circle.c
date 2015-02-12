#include<stdio.h>

void print_circle_area(double measure, char r_or_d);
double circle_area(double measure, char r_or_d);

int main()
{
	double measure;
	char rad_or_dia;
	printf("Will you be giving radius or diameter[r/d]: ");
	scanf("%c", &rad_or_dia);

	if (rad_or_dia == 'r' || rad_or_dia == 'R')
	{
		printf("Give the radius: ");
	} else if (rad_or_dia == 'd' || rad_or_dia == 'D') {
		printf("Give the diameter: ");	
	} else {
		printf("Bad value.");
		return 0;
	}
	
	scanf("%lf", &measure);

	print_circle_area(measure, rad_or_dia);	

	return 0;
}

/**
* Prints the area of a circle given radius or diameter
* @param measure The radius or diameter of the circle
* @param r_or_d A character to repersent that you are either passing in a radius or diameter
*/
void print_circle_area(double measure, char r_or_d)
{
	printf("Circle ");
	if (r_or_d == 'r')
	{
		printf("radius");
	} else {
		printf("diameter");
	}

	printf(" %.2lf is %.2lf in area\n", measure, circle_area(measure, r_or_d));
}

/**
* Calculates the area of a circle given radius or diameter
* @param r_or_d A character to repersent that you are either passing in a radius or diameter
* @return The area of the circle
*/
double circle_area(double measure, char r_or_d)
{
	if (r_or_d == 'd')
	{
		measure /= 2;
	}
	return 3.14 * measure * measure;	
}
