#include<stdio.h>


int main() 
{
	int *p;
	int a, b;
	a = 0;
	b = 1;
	
	p = a;
	printf("%d\n", *p); 

	b = &p;
	
	printf("%d\n", b); 

 	return 0;
}
