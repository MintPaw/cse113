#include <stdlib.h>
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"
#include "matrix.h"

int main(int argc, char *argv[])
{
	int stage = 0;
	int width = 800;
	int height = 600;
	int sprite_size = 1; /* either 2, 4, 8, or 16 */
	//int m = -66;
	//int n = -10;
        /* colors are RGB model valid values [0, 255] */
	unsigned char red = 140;
	unsigned char green = 145;
	unsigned char blue = 250;
	struct sdl_info_t sdl_info; /* this is needed to graphically display the game */
        
	/* set up SDL -- works with SDL2 */
	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	/* your life initialization code here */
	
	struct Matrix matrix1;
	struct Matrix matrix2;
	setup_matrix(width / 2, height / 2, FULL, &matrix1);
	setup_matrix(width / 2, height / 2, FULL, &matrix2);

	parse_file(width, height, fopen(argv[1], "r"), &matrix1);
	//set_value(400, 0, 1, &matrix1);

	/* Main loop: loop forever. */
	while (1)
	{
		/* your game of life code goes here  */

		/* change the  modulus value to slow the rendering */
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

		/* Poll for events, and handle the ones we care about. 
		* You can click the X button to close the window
		*/
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
                        /* If escape is pressed, return (and thus, quit) */
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