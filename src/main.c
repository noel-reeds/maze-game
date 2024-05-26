#include <SDL2/SDL.h>
#include "main.h"
/**
 * main - entry point of a C program
 * Return: returns void
 */
int main(void)
{
    SDL_Instance instance;
    if (init_instance(&instance) != 0)
        return (1);
    while ("C is awesome")
    {
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 255, 255);
        SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(instance);
        SDL_RenderPresent(instance.renderer);
    }
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
    return (0);
} 
