#include <stdio.h>
#include "life.h"

void parse_file(int width, int height, FILE *file, char a[height][width])
{
	char file_string[999];
	int x;
	int y;

	while(!feof(file))
	{
		fscanf(file, "%[^\n]\n", file_string);
		if (file_string[0] == '#')
		{
			continue;
		} else {
			sscanf(file_string, "%d %d", &x, &y);
		}
	}
}

void print_2d_array(int width, int height, char a[height][width])
{
	int i;
	int j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}

//void set_value(); --------------------------------------------------------------------------------------------