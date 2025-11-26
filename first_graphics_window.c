/* using SDL and standard IO */
#include "main.h"
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
/**
 * main - game etry point
 *
 * Return: 0 for success
 */
int main(void)
{
	/* the window we'll be rendering to */
	SDL_Window *window = NULL;
	/* the surface contained by the window */
	SDL_Surface *screenSurface = NULL;
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
	}
	else
	{
	/* create a window */
		window = SDL_CreateWindow(
				"MAZE GAME!", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!window)
		{
			printf("Window could not be created! SDL_Error: %s", SDL_GetError());
		}
		/* get window surface */
		screenSurface = SDL_GetWindowSurface(window);
		/* fill surface with white */
		SDL_FillRect(
				screenSurface, NULL,
				SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		/* update window */
		SDL_UpdateWindowSurface(window);
		/* hack to get window stay up */
		SDL_Event e;
		bool quit = false;

		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					quit = true;
			}
		}
	}
	/* destroy window */
	SDL_DestroyWindow(window);
	/* quit SDL subsytems */
	SDL_Quit();
	return (0);
}
