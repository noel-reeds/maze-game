#include "../inc/main.h"
/**
 * init_instance - initializes an instance
 * @instance: pointer to windows and renderer struct
 * Return: returns 0 for success, 1 for an err.
 */
int init_instance(SDL_Instance *instance)
{
	/* Initializes an SDL instance */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return (1);
	}

	/* create a new window instance */
	instance->window = SDL_CreateWindow("Battle Snipper",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (instance->window == NULL)
	{
		printf("Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
