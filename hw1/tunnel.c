#include <stdio.h>

void main()
{
	int i;
	for (i = 0; 1; i++)
	{
		if (!(i % 2))
		{
			printf("##    ##########################################################################\n");
		} else if (!(i % 3)) {
			printf("###    #########################################################################\n");
		} else {
			printf("#    ###########################################################################\n");
		}
	}
}
