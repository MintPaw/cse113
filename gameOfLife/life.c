/**
* @file life.c
* @brief Contains most of the functionality of The Game of Life
* @author Jeru Sanders
* @date 4/28/15
* @todo None
* @bug None
*/

#include <stdio.h>
#include <stdlib.h>
#include "life.h"


/**
* Stores a 1.06 life file in a matrix
* @param width The width of the matrix
* @param height The height of the matrix
* @param start_x height The origin x
* @param start_y height The origin y
* @param file The file to load from (and close)
* @param m The matrix to store the pattern in
*/
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

	fclose(file);
}

/**
* Computes the next stage of the game
* @param start The current matrix
* @param end The matrix to build the next step in
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

/**
* Crates an empty matrix
* @param width The matrix width 
* @param height The matrix height 
* @param wrapping The wrapping mode
* @param m The matrix reference
*/
void setup_matrix(int width, int height, char wrapping, struct Matrix *m)
{
	m->width = width;
	m->height = height;
	m->wrapping_mode = wrapping;

	int x;

	m->data = calloc(m->width, sizeof(unsigned char *));
	if(!m->data)
	{
		return;
	}

	for(x = 0; x < m->width; x++)
	{
		m->data[x] = calloc(m->height, sizeof(unsigned char));
		
		if (!m->data[x])
		{
			destroy_matrix(m);
			return;
		}
	}
}

// TODO(jeru): Comment
void destroy_matrix(struct Matrix *m)
{
	int x;
	for(x = 0; x < m->width; x++)
	{
		free(m->data[x]);
	}

	free(m->data);
}

/**
* Sets a value in the matrix
* @param x Position x
* @param y Position y
* @param value The value to store
* @param matrix The matrix to store it in
*/
void set_value(int x, int y, char value, struct Matrix *m)
{
	normalize_points(&x, &y, m->width, m->height, m->wrapping_mode);

	if (x == -1)
	{
		return;
	}

	m->data[x][y] = value;
}

/**
* Gets a value from the matrix
* @param x Position x
* @param y Position y
* @param matrix The matrix to get it from
* @return The value
*/
unsigned char get_value(int x, int y, struct Matrix *m)
{
	normalize_points(&x, &y, m->width, m->height, m->wrapping_mode);

	if (x == -999)
	{
		return 0;
	}

	return m->data[x][y];
}

/**
* Empties out a matrix
* @param m The matrix to empty
*/
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

/**
* Normalizes points based on wrapping mode
* @param x Position x
* @param y Position y
* @param width The width
* @param height The height
* @param wrapping The wrapping_mode
*/
void normalize_points(int *x, int *y, int width, int height, char wrapping)
{
	if (wrapping == NONE) {
		if (*x < 0 || *x >= width || *y < 0 || *y >= height) {
			*x = -999;
			return;
		}
	} else if (wrapping == TORUS) {
		if (*x < 0) {
			*x = width + *x;
		}

		if (*y < 0) {
			*y = height + *y;
		}

		*y = *y % height;
		*x = *x % width;
	} else if (wrapping == BOTTLE) {
		if (*y < 0 || *y >= height)
		{
			*x *= -1;
		}

		if (*x < 0) {
			*x = width + *x;
		}

		if (*y < 0) {
			*y = height + *y;
		}

		*y = *y % height;
		*x = *x % width;
	}
}