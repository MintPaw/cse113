#ifndef LIFE_H_
#define LIFE_H_

#include "matrix.h"

void parse_file(int width, int height, int start_x, int start_y, FILE *file, struct Matrix *m);
void compute_matrix(struct Matrix *start, struct Matrix *end);

#endif
