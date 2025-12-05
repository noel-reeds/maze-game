/* using SDL and standard IO */
#include "main.h"
#include <SDL.h>

/* the window we'll be rendering to */
SDL_Window *window = NULL;
/* the surface contained by the window */
SDL_Surface *screenSurface = NULL;
/* image to load and show on the screen */
SDL_Surface *hello_world = NULL;

/**
 * main - game etry point
 *
 * Return: 0 for success
 */
int main(void)
{
	/* starts up SDL and creates a window */
	if (!initialize_sdl())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		/* loads media */
		if (!loading_media())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			/* apply image to screen surface */
			SDL_BlitSurface(hello_world, NULL, screenSurface, NULL);
			SDL_UpdateWindowSurface(window);
			/* window to stay up */
			SDL_Event e;
			bool quit = false;

			while (!quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}
		}
		/* free mem and close SDL */
		close_sdl();
	}
	return (0);
}

/**
 * initialize_sdl - initializes SDL libr.
 *
 * Return: true or false
 */
bool initialize_sdl(void)
{
	/* initialization flag */
	bool success = true;
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		success = false;
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
			success = false;
		}
		else
		{
			/* get window surface */
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return (success);
}

/**
 * loading_media - loads media to render.
 *
 * Return: true or false
 */
bool loading_media(void)
{
	/* loading success flag */
	bool success = true;
	/* load splash image */
	hello_world = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
	if (!hello_world)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return (success);
}

/**
 * close_sdl - deallocate surface and closes SDL.
 *
 * Return: void.
 */
void close_sdl(void)
{
	/* deallocate surface */
	SDL_FreeSurface(hello_world);
	hello_world = NULL;
	/* destroy window */
	SDL_DestroyWindow(window);
	window = NULL;
	/* quit sdl subsytems */
	SDL_Quit();
}
