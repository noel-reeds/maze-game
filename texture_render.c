#include "main.h"
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
	texture = load_texture("04_key_presses/press.bmp");
	if (!texture)
	{
		printf("Failed to load media texture\n");
		success = false;
	}
	return success;
}
