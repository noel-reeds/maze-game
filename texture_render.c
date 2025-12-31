#include "main.h"
_Texture *bg_texture = NULL;

/**
 * load_texture - loads image texture
 *
 *@image_path: specifies path to image
 *
 *Return: returns pixel info.
 */
SDL_Texture *load_texture(const char *image_path)
{
	/* The final texture */
	SDL_Texture *new_texture = NULL;

	/* Load image at specified location */
	SDL_Surface *loaded_surface = IMG_Load(image_path);

	if (!loaded_surface)
		printf("Unable to load image %s! SDL_image Error: %s\n",
				image_path, IMG_GetError());
	else
	{
		/* Create a texture from surface pixels */
		new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);

		if (!new_texture)
			printf("Unable to create texture from %s! SDL Error: %s\n",
					image_path, SDL_GetError());
		else
			SDL_FreeSurface(loaded_surface);
	}
	return (new_texture);
}

/**
 * load_media_texture - loads texture from src path
 *
 *Return: void
 */
bool load_media_texture(void)
{
	/* Loading success flag */
	bool success = true;
	/* Load PNG texture */
	if (!load_from_file(mod_texture, "13_alpha_blending/fadeout.png"))
	{
		printf("Failed to load front texture\n");
		success = false;
	}
	else
		set_blend_mode(mod_texture->m_texture, SDL_BLENDMODE_BLEND);
	if (!load_from_file(bg_texture, "13_alpha_blending/fadein.png"))
	{
		printf("Failed to load background texture\n");
		success = false;
	}
	return (success);
}

/**
 * set_color - modulate color
 *
 *Return: void.
 */
void set_color(uint8_t red, uint8_t green, uint8_t blue)
{
	SDL_SetTextureColorMod(mod_texture->m_texture, red, green, blue);
}
