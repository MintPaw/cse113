/**
* @file gl.c
* @brief Simulates the game of life
* @details An SDL program that allows you to load and execute 1.06 life files with different options
* @author Jeru Sanders
* @date 4/28/15
* @todo Add Klein mode
* @bug None
*/

#include <stdlib.h>
#include <unistd.h>
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"

int main(int argc, char *argv[])
{
	int stage = 0;
	int width = 800;
	int height = 600;
	int sprite_size = 2; /* either 2, 4, 8, or 16 */
	int start_x = 0;
	int start_y = 0;
	int edge = NONE;
	unsigned char red = 140;
	unsigned char green = 145;
	unsigned char blue = 250;
	struct sdl_info_t sdl_info;

	char file_path[265];
	int c;
	while ((c = getopt(argc, argv, "w:h:e:r:g:b:s:f:o:H")) != -1)
	{
		if (c == 'f')
		{
			strcpy(file_path, optarg);
		} else if (c == 'w') {
			width = atoi(optarg);
		} else if (c == 'h') {
			height = atoi(optarg);
		} else if (c == 'r') {
			red = atoi(optarg);
		} else if (c == 'g') {
			green = atoi(optarg);
		} else if (c == 'b') {
			blue = atoi(optarg);
		} else if (c == 's') {
			sprite_size = atoi(optarg);
		} else if (c == 'o') {
			sscanf(optarg, "%d,%d", &start_x, &start_y);
		} else if (c == 'e') {
			if (!strcmp(optarg, "hedge"))
			{
				edge = 0;
			} else if (!strcmp(optarg, "torus")) {
				edge = 1;
			} else if (!strcmp(optarg, "klein")) {
				edge = 2;
			}
		} else if (c == 'H') {
			printf("-w Width\n");
			printf("-h Height\n");
			printf("-e Edge type ('hedge' or 'torus')\n");
			printf("-r Red value\n");
			printf("-b Blue value\n");
			printf("-g Green value\n");
			printf("-s Sprite size (2, 4, 8, or 16)\n");
			printf("-f 1.06 life file\n");
			printf("-o The origin (-o 2,3)\n");
			printf("-H Displays this message\n");
			return 0;
		}
	}

	printf("Starting...\n");
	printf("width: %d\nheight: %d\nred: %d\ngreen: %d\nblue: %d\norigin: %d,%d\nfile: %s\n",
		width,
		height,
		red,
		green,
		blue,
		start_x,
		start_y,
		file_path);

	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	width /= sprite_size;
	height /= sprite_size;
	
	struct Matrix matrix1;
	struct Matrix matrix2;
	setup_matrix(width, height, edge, &matrix1);
	setup_matrix(width, height, edge, &matrix2);

	parse_file(width, height, start_x, start_y, fopen(file_path, "r"), &matrix1);

	while (1)
	{
		if (SDL_GetTicks() % 1 == 0)
		{
			if (stage == 0)
			{
				sdl_render_life(&sdl_info, matrix1.data);
				compute_matrix(&matrix1, &matrix2);
				stage = 1;
			} else if (stage == 1) {
				sdl_render_life(&sdl_info, matrix2.data);
				compute_matrix(&matrix2, &matrix1);
				stage = 0;
			}
		}

		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
				case SDL_KEYDOWN:
					break;
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						return 0;
					break;
				case SDL_QUIT:
					destroy_matrix(&matrix1);
					destroy_matrix(&matrix2);
					return(0);
			}
		}
	}

	return 0;
}