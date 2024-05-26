#include <SDL2/SDL.h>
#include "main.h"
/**
 * draw_stuff - render a random stuff
 *
 *@instance: SDL instance.
 *
 * Return: returns void
 */
void draw_stuff(SDL_Instance instance)
{
	SDL_Point cordinates[] = {
		{50, 50},
		{200, 200},
		{300, 100},
		{450, 200}
	};
	int numpoints = sizeof(cordinates) / sizeof(cordinates[0]);
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLines(instance.renderer, cordinates, numpoints);
}
