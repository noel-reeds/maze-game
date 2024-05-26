#include <SDL2/SDL.h>
#include <stdio.h>
/**
 * main - initializes an SDL instance.
 *
 * Return: returns 0 for success, -ve err code for failure.
 */
int main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	/* Initialize an SDL instance */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	/* creates a new window instance */
	window = SDL_CreateWindow("Battle Snipper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	/* create a new renderer linked to the window */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	while ("Battle Snipper")
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
