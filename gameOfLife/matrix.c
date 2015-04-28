#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void setup_matrix(int width, int height, char wrapping, struct Matrix *m)
{
	m->width = width;
	m->height = height;
	m->wrapping_mode = wrapping;
	m->data = calloc(height, sizeof(unsigned char *));

	int i, j;
	for (i = 0; i < height; i++)
	{
		m->data[i] = calloc(width, sizeof(unsigned char));
	}
}

void print_matrix(struct Matrix *m)
{
	int i, j;

	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			printf("%d", m->data[i][j]);
		}
		printf("\n");
	}
}

void print_matrix_info(struct Matrix *m)
{
	int ones = 0;
	int zeros = 0;
	int i, j;

	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			if (m->data[i][j] == 0)
			{
				zeros++;
			} else if (m->data[i][j] == 1) {
				ones++;
			}
		}
	}

	printf("This is a %dx%d matrix with %d ones and %d zeros\n",
		m->width,
		m->height,
		ones,
		zeros
		);
}

void set_value(int x, int y, char value, struct Matrix *m)
{
	if (m->wrapping_mode == NONE)
	{
		if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		{
			return;
		}
	} else if (m->wrapping_mode == FULL) {
		int old_x = x;
		int old_y = y;
		x = normalize_point(x, m->width);
		y = normalize_point(y, m->height);
		if (old_x != x || old_y != y)
		{
			//printf("Point %d, %d normalized to ", old_x, old_y);
			//printf("%d, %d\n", x, y);
		}
	}

	m->data[y][x] = value;
}

unsigned char get_value(int x, int y, struct Matrix *m)
{
	if (m->wrapping_mode == NONE)
	{
		if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		{
			return 0;
		}
	} else if (m->wrapping_mode == FULL) {
		x = normalize_point(x, m->width);
		y = normalize_point(y, m->height);
	}


	return m->data[y][x];
}

void empty_matrix(struct Matrix *m)
{
	int i, j;

	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			set_value(j, i, 0, m);
		}
	}
}

int normalize_point(int p, int max)
{
	if (p < 0)
	{
		return max + p;
	} else if (p >= max) {
		return p % max / 2;
	}

	return p;
}