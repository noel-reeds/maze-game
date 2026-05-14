#include "main.h"
/**
 * close_sdl - deallocate surface and closes SDL.
 *
 * Return: void.
 */
void close_sdl2(void)
{
	free_texture_structs(texture, ctx);
	texture = NULL;
	ctx = NULL;
	SDL_Quit();
}
