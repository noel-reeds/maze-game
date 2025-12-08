/* using SDL and standard IO */
#include "main.h"
#include <SDL.h>

/* Key press surface constants */
enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

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
			SDL_Event event_e;
			bool quit = false;

			while (!quit)
			{
				while (SDL_PollEvent(&event_e))
				{
					switch (event_e.type)
					{
					case SDL_MOUSEMOTION:
						SDL_Log("Mouse position: (%d, %d)\n", event_e.motion.x, event_e.motion.y);
						break;
					case SDL_QUIT:
						quit = true;
						break;
					default:
						SDL_Log("Unhandled Event!");
						break;
					case SDL_KEYDOWN:
						SDL_Log("%s key pressed!\n", SDL_GetKeyName(event_e.key.keysym.sym));
						break;
					case SDL_KEYUP:
						break;
					}
				}
			}
			SDL_Log("Event queue is empty.");
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
