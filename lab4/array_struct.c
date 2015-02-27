#include "array_struct.h"
#include <stdio.h>


int main(void)
{

	struct data_t data[SIZE];

	/* data initialization calls */
	fill_array(data, 0, 'A', 23, 74);
	fill_array(data, 1, 'B', 22, 64);
	fill_array(data, 2, 'C', 19, 68);
	fill_array(data, 3, 'D', 20, 76);
	fill_array(data, 4, 'E', 22, 62);

	return 0;
}

