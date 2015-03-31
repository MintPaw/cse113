#include <stdio.h>

int main(void)
{
	/* char s[] = "c run, run c run"; */
	char *s = "c run, run c run";

	char *p = s; 		/* p points to the beginning of s */

	printf("the original string:\n");
		printf("%s\n", s);

	while(*p != '\0') { 	/* dereference what p points to */
		if (*p == 'r')
			*p = 'f'; /* change the value */
		p++; 		/* increment the address */
	}

	printf("\nthe changed string:\n");
		printf("%s\n", s);

	return 0;
}
