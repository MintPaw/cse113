#include <stdio.h>

int main()
{
	double p = 3.14159;
	double *pp = &p;

	*pp = 2.71828;

	printf("p is at %p\np equals %f\n", pp, p);

	return 0;
}