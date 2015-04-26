#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void setup_matrix(int width, int height, char wrapping, struct Matrix *m)
{
	m->width = width;
	m->height = height;
	m->wrapping_mode = wrapping;
	m->data = malloc(width * sizeof(unsigned char *));

	int i, j;
	for (i = 0; i < width; i++)
	{
		m->data[i] = malloc(height * sizeof(unsigned char));
	}

	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			set_value(i, j, 0, m);
		}
	}
}

void print_matrix(struct Matrix *m)
{
	int i;
	int j;

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
	//if (x >= 799 || y >= 599) printf("Setting %d, %d\n", x, y);
	if (m->wrapping_mode == NONE)
	{
		if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		{
			return;
		}
	} else if (m->wrapping_mode == FULL) {
		if (x < 0)
		{
			x = m->width + x;
		} else if (x >= m->width) {
			x = x % m->width;
		}
		
		if (y < 0)
		{
			y = m->height + y;
		} else if (y >= m->height) {
			y = y % m->height;
		}
	}

	m->data[x][y] = value;
}

unsigned char get_value(int x, int y, struct Matrix *m)
{
	//if (x >= 799 || y >= 599) printf("Getting %d, %d\n", x, y);
	
	if (m->wrapping_mode == NONE)
	{
		if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		{
			return 0;
		}
	} else if (m->wrapping_mode == FULL) {
		if (x < 0)
		{
			x = m->width + x;
		} else if (x >= m->width) {
			x = x % m->width;
		}
		
		if (y < 0)
		{
			y = m->height + y;
		} else if (y >= m->height) {
			y = y % m->height;
		}
	}


	return m->data[x][y];
}

void empty_matrix(struct Matrix *m)
{
	int i, j;

	for (i = 0; i < m->height; i++)
	{
		for (j = 0; j < m->width; j++)
		{
			m->data[i][j] = 0;
		}
	}
}