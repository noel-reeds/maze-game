#include "main.h"
#include "mouse.h"
btt_e_handlr buttons[ TOTAL_BUTTONS ];
SDL_Surface *KeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface *screenSurface = NULL;
SDL_Window *window = NULL;
SDL_Surface *currentSurface = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
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

		/* Allocate memory for texture structs */
		press = malloc(sizeof(_Texture));
		up = malloc(sizeof(_Texture));
		down = malloc(sizeof(_Texture));
		left = malloc(sizeof(_Texture));
		right = malloc(sizeof(_Texture));

		if (!load_media_surface())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			/* window to stay up */
			bool quit = false;
			SDL_Event event_e;
			/* current rendered texture */
			_Texture *current_texture = NULL;
			while (!quit)
			{
				while (SDL_PollEvent(&event_e) != 0)
				{
					/* user requests quit */
					if (event_e.type == SDL_QUIT)
						quit = true;
					/* set texture based on the current key state */
					const Uint8 *keystates = SDL_GetKeyboardState(NULL);
					if (keystates[SDL_SCANCODE_INSERT])
						current_texture = up;
					if  (keystates[SDL_SCANCODE_PAGEDOWN])
						current_texture = down;
					if (keystates[SDL_SCANCODE_RIGHT])
						current_texture = right;
					if (keystates[SDL_SCANCODE_LEFT])
						current_texture = left;
					else
						current_texture = press;
				}
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(renderer);
				/* render current texture */
				render(renderer, current_texture,
						0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE);
				SDL_RenderPresent(renderer);
			}
		}
		SDL_Log("Event queue is empty.");
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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		success = false;
	}
	else
	{
		/* check for joysticks */
		if (SDL_NumJoysticks() < 1)
			printf("Warning: No joysticks connected\n");
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
			/* create a renderer for the window */
			renderer = SDL_CreateRenderer(
					window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!renderer)
			{
				printf("Renderer could not be created! "
						"SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				/* Initialize PNG loading */
				int img_flags = IMG_INIT_PNG;

				if (!(IMG_Init(img_flags) & img_flags))
				{
					printf("SDL_image could not initialize! "
							"SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
							TTF_GetError());
					success = false;
				}
			}
		}
	}
	return (success);
}

/**
 * load_media_surface - loads media to render.
 *
 * Return: true or false
 */
bool load_media_surface(void)
{
	/* loading success flag */
	bool success = true;

	if (!load_from_file(press, "18_key_states/press.png"))
		success = false;
	if (!load_from_file(up, "18_key_states/up.png"))
		success = false;
	if (!load_from_file(down, "18_key_states/down.png"))
		success = false;
	if (!load_from_file(left, "18_key_states/left.png"))
		success = false;
	if (!load_from_file(right, "18_key_states/right.png"))
		success = false;
	return (success);
}

/**
 * close_sdl - deallocate surface and closes SDL.
 *
 * Return: void.
 */
void close_sdl(void)
{
	/* Free textures and structs */
	free_texture(ss_texture);
	for (int m = 0; m < 4; m++)
	{
		free(sprite_clips[m]);
	}
	/* deallocate surface */
	SDL_DestroyTexture(texture);
	texture = NULL;
	/* destroy window */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	TTF_CloseFont(font);
	font = NULL;
	/* quit sdl subsytems */
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

/**
 * loadSurface - load image at specified path
 *
 *@surface_path: image path
 *
 * Return: SDL_Surface
 */
SDL_Surface *load_surface(const char *surface_path)
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
	return (optimized_surface);
}
