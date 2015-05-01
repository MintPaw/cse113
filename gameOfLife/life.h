/**
* @file life.h
* @brief The header for life.c
* @author Jeru Sanders
* @date 4/28/15
*/

#ifndef LIFE_H_
#define LIFE_H_

#define NONE 0
#define TORUS 1
#define BOTTLE 2

struct Point
{
	int x;
	int y;
};

struct Matrix
{
	int wrapping_mode;
	int width;
	int height;
	unsigned char **data;
};

void setup_matrix(int width, int height, char wrapping, struct Matrix *m);
void destroy_matrix(struct Matrix *m);
void set_value(int x, int y, char value, struct Matrix *m);
unsigned char get_value(int x, int y, struct Matrix *m);
void empty_matrix(struct Matrix *m);
void normalize_points(int *x, int *y, int width, int height, char wrapping);


void parse_file(int width, int height, int start_x, int start_y, FILE *file, struct Matrix *m);
void compute_matrix(struct Matrix *start, struct Matrix *end);

#endif
