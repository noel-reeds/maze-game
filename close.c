#include "main.h"
/**
 * close_sdl - deallocate surface and closes SDL.
 *
 * Return: void.
 */
void close_sdl(void)
{
	/* Free textures and structs */
	free_texture(texture);
	/* deallocate surface */
	SDL_DestroyTexture(texture->m_texture);
	texture = NULL;
	/* destroy window */
	SDL_DestroyRenderer(ctx->rndr);
	SDL_DestroyWindow(ctx->window);
	ctx->window = NULL;
	ctx->rndr = NULL;

	SDL_Quit();
}
