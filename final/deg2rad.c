/**
* @file deg2rad.c
* @brief Converts degrees to radians
* @details Converts degrees to radians
* @author Jeru Sanders
* @date 5/7/15
* @todo None
* @bug None
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	printf("%lf\n", n * M_PI / 180);

	return 0;
}