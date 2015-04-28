#ifndef MATRIX_H_
#define MATRIX_H_
#define NONE 0
#define FULL 1

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
void print_matrix(struct Matrix *m);
void print_matrix_info(struct Matrix *m);
void set_value(int x, int y, char value, struct Matrix *m);
unsigned char get_value(int x, int y, struct Matrix *m);
void empty_matrix(struct Matrix *m);
int normalize_point(int p, int max);

#endif
