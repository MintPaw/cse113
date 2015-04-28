#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void setup_matrix(int width, int height, char wrapping, struct Matrix *m)
{
	m->width = height;
	m->height = width;
	m->wrapping_mode = wrapping;

	int i;
	int j;
	m->data = calloc(m->height, sizeof(unsigned char *));
	if(!m->data)
	{
		return;
	}

	for(i = 0; i < m->height; i++)
	{
		m->data[i] = calloc(m->width, sizeof(unsigned char));
		if (!m->data[i])
		{
			for(j = 0; j < i; j++)
			free(m->data[j]);
			free(m->data);
			return;
		}
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
		if (x < 0 || x >= m->width / 2 || y < 0 || y >= m->height / 2)
		{
			return;
		}
	} else if (m->wrapping_mode == FULL) {
		int old_x = x;
		int old_y = y;
		x = normalize_point(x, m->width / 2);
		y = normalize_point(y, m->height / 2);
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
		if (x < 0 || x >= m->width / 2 || y < 0 || y >= m->height / 2)
		{
			return 0;
		}
	} else if (m->wrapping_mode == FULL) {
		x = normalize_point(x, m->width / 2);
		y = normalize_point(y, m->height / 2);
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
		return p % max;
	}

	return p;
}