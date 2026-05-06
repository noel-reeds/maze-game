#include "main.h"

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
		new_texture = SDL_CreateTextureFromSurface(ctx->rndr, loaded_surface);

		if (!new_texture)
			printf("Unable to create texture from %s! SDL Error: %s\n",
					image_path, SDL_GetError());
		else
			SDL_FreeSurface(loaded_surface);
	}
	return (new_texture);
}

bool load_media_texture(void)
{
	/* Loading success flag */
	bool success = true;
	/* Load PNG texture */
	if (!load_from_file(texture, "foo/15_rotation_and_flipping/arrow.png"))
	{
		printf("Failed to load walking animation texture\n");
		success = false;
	}
	return (success);
}

void set_color(uint8_t red, uint8_t green, uint8_t blue)
{
	SDL_SetTextureColorMod(texture->m_texture, red, green, blue);
}
