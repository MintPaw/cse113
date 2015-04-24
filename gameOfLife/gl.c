#include <stdlib.h>
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"

int main(int argc, char *argv[])
{
	int width = 800;
	int height = 600;
	int sprite_size = 4; /* either 2, 4, 8, or 16 */
	int m = -66;
	int n = -10;
        /* colors are RGB model valid values [0, 255] */
	unsigned char red = 140;
	unsigned char green = 145;
	unsigned char blue = 250;
        struct sdl_info_t sdl_info; /* this is needed to graphically display the game */
        
        /* set up SDL -- works with SDL2 */
	init_sdl_info(&sdl_info, width, height, sprite_size, red, green, blue);

	/* your life initialization code here */
	
	char matrix1[height][width];
	char matrix2[height][width];

	int i;
	int j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			matrix1[i][j] = 0;
			matrix2[i][j] = 0;
		}
	}

	parse_file(width, height, fopen(argv[1], "r"), matrix1);

	//print_2d_array(width, height, matrix1);

        /* Main loop: loop forever. */
	while (1)
	{


		/* your game of life code goes here  */		

		/* change the  modulus value to slow the rendering */
		 /* if (SDL_GetTicks() % 1 == 0) */
			//sdl_test(&sdl_info, m, n);

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