#include <stdio.h>
#include "life.h"
#include "matrix.h"

void parse_file(int width, int height, int start_x, int start_y, FILE *file, struct Matrix *m)
{
	char file_string[999];
	int x;
	int y;

	struct Point points[999];
	int current_point = 0;

	while(!feof(file))
	{
		fscanf(file, "%[^\n]\n", file_string);
		if (file_string[0] != '#')
		{
			sscanf(file_string, "%d %d", &x, &y);
			points[current_point].x = x;
			points[current_point].y = y;
			current_point++;
		}
	}

	int i;
	int lowest_x = 0;
	int lowest_y = 0;
	for (i = 0; i < current_point; i++)
	{
		if (points[i].x < lowest_x)
		{
			lowest_x = points[i].x;
		}

		if (points[i].y < lowest_y)
		{
			lowest_y = points[i].y;
		}
	}

	lowest_x -= start_x;
	lowest_y -= start_y;

	for (i = 0; i < current_point; i++)
	{
		points[i].x += -lowest_x;
		points[i].y += -lowest_y;
		set_value(points[i].x, points[i].y, 1, m);
	}
}

/*
	Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
	Any live cell with more than three live neighbours dies, as if by overcrowding.
	Any live cell with two or three live neighbours lives, unchanged, to the next generation.
	Any dead cell with exactly three live neighbours cells will come to life.
*/
void compute_matrix(struct Matrix *start, struct Matrix *end)
{
	int x;
	int y;
	int n;
	int l;
	char set = 0;

	empty_matrix(end);

	for (y = 0; y < end->height; y++)
	{
		for (x = 0; x < end->width; x++)
		{
			l = get_value(x, y, start);
			n = 0;
			set = 0;

			if (get_value(x + 1, y, start)) n++;
			if (get_value(x, y + 1, start)) n++;
			if (get_value(x - 1, y, start)) n++;
			if (get_value(x, y - 1, start)) n++;
			if (get_value(x - 1, y - 1, start)) n++;
			if (get_value(x + 1, y + 1, start)) n++;
			if (get_value(x + 1, y - 1, start)) n++;
			if (get_value(x - 1, y + 1, start)) n++;

			if (l && (n < 2 || n > 3))
			{
				set = 0;
			}
			if (!l && (n == 3)) {
				set = 1;
			} 
			if (l && (n == 2 || n == 3)) {
				set = 1;
			}

			if (set) set_value(x, y, 1, end);
		}
	}
}