#include "main.h"
/**
 * set_blend_mode - sets blend mode.
 *
 *Return: void
 */
void set_blend_mode(SDL_Texture *Te, SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(Te, blending);
}

/**
 * set_alpha - sets alpha modulation
 *
 *@alpha: sets opacity
 *
 *Return: void
 */
void set_alpha(uint8_t alpha)
{
	SDL_SetTextureAlphaMod(mod_texture->m_texture, alpha);
}
