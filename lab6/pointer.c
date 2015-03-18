#include<stdio.h>


int main() 
{
	int *p;
	int a, b;
	a = 0;
	b = 1;

	//corrected Jeru Sanders 3/18/2015
	p = &a;
	printf("%d\n", *p); 

	//corrected Jeru Sanders 3/18/2015
	//b = &p;
	
	printf("%d\n", b); 

 	return 0;
}
