/* using SDL and standard IO */
#include "main.h"

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
			/* apply DEFAULT screen surface */
			currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
			SDL_Rect stretched;
			stretched.x = 0;
			stretched.y = 0;
			stretched.w = SCREEN_WIDTH;
			stretched.h = SCREEN_HEIGHT;
			SDL_BlitScaled(currentSurface, NULL, screenSurface, &stretched);
			SDL_UpdateWindowSurface(window);
			/* window to stay up */
			bool quit = false;
			/* event handler */
			SDL_Event event_e;
			/* while application is running */
			while(!quit)
			{
				while( SDL_PollEvent(&event_e) != 0 )
				{
					/* user requests quit */
					if( event_e.type == SDL_QUIT )
					{
						quit = true;
					}
					/* user presses a key */
					else if (event_e.type == SDL_KEYDOWN)
					{
						/* select surfaces based on key press */
						switch( event_e.key.keysym.sym )
						{

							case SDLK_UP:
								currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
								break;

							case SDLK_DOWN:
								currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
								break;

							case SDLK_LEFT:
								currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
								break;

							case SDLK_RIGHT:
								currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
								break;

							default:
								currentSurface = KeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
								break;
						}
						SDL_BlitScaled(currentSurface, NULL, screenSurface, &stretched);
						SDL_UpdateWindowSurface(window);
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
			printf("Window could not be created! SDL_Error: %s",
					SDL_GetError());
			success = false;
		}
		else
		{
			/* Initialize PNG loading */
			int img_flags = IMG_INIT_PNG;
			if ( !(IMG_Init( img_flags ) & img_flags ))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n",
						IMG_GetError());
				success = false;
			}
			else
			{
				/* Get window surface */
				screenSurface = SDL_GetWindowSurface(window);
			}
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
	/* load DEFAULT surface */
	KeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface(
			"04_key_presses/press.bmp");
	if ( !KeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] )
	{
		printf("failed to load DEFAULT image!\n");
		success = false;
	}
	/* load UP surface */
	KeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface(
			"04_key_presses/up.bmp");
	if ( !KeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] )
	{
		printf("unable to load UP image!\n");
		success = false;
	}
	/* load DOWN surface */
	KeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface(
			"04_key_presses/down.bmp");
	if ( !KeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] )
	{
		printf("unable to load DOWN image!\n");
		success = false;
	}
	/* load LEFT surface */
	KeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface(
			"04_key_presses/left.bmp");
	if ( !KeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] )
	{
		printf("unable to load LEFT image!\n");
		success = false;
	}
	/* load RIGHT surface */
	KeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface(
			"04_key_presses/right.bmp");
	if ( !KeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] )
	{
		printf("unable to load RIGHT image!\n");
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
	SDL_FreeSurface(currentSurface);
	currentSurface = NULL;
	/* destroy window */
	SDL_DestroyWindow(window);
	window = NULL;
	/* quit sdl subsytems */
	SDL_Quit();
}

/**
 * loadSurface - load image at specified path
 *
 *@hello_world - image path
 *
 * Return: SDL_Surface
 */
SDL_Surface *loadSurface(const char *surface_path)
{
	/* The final optimized image */
	SDL_Surface *optimized_surface = NULL;
	/* load image at specified path */
	SDL_Surface *loaded_surface = IMG_Load(surface_path);
	if (!loaded_surface)
	{
		printf("unable to load image %s! SDL Error: %s\n",
				surface_path, IMG_GetError());
	}
	else
	{
		/* convert surface to screen format */
		optimized_surface = SDL_ConvertSurface(
								loaded_surface,
								screenSurface->format,
								0);
		if (!optimized_surface)
		{
			printf("unable to optimize image %s! SDL Error: %s\n",
					surface_path, SDL_GetError());
		}
		/* remove old loaded surface */
		SDL_FreeSurface(loaded_surface);
	}
	return optimized_surface;
}
