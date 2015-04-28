#include <stdlib.h>
#include <unistd.h>
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"
#include "matrix.h"

int main(int argc, char *argv[])
{
	int stage = 0;
	int width = 800;
	int height = 600;
	int sprite_size = 4; /* either 2, 4, 8, or 16 */
	int start_x = 0;
	int start_y = 0;
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
		}
	}
	
	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	width /= sprite_size;
	height /= sprite_size;

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
	
	struct Matrix matrix1;
	struct Matrix matrix2;
	setup_matrix(width, height, FULL, &matrix1);
	setup_matrix(width, height, FULL, &matrix2);

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
					return(0);
			}
		}
	}
	return 0;
}