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
	bool _ss = load_from_file(ss_texture, "10_color_keying/dots.png");
	if (!_ss)
	{
		printf("Failed to load sprite sheet texture\n");
		success = false;
	}
	else
	{
		sprite_clips[ 0 ]->x = 0;
		sprite_clips[ 0 ]->y = 0;
		sprite_clips[ 0 ]->w = 100;
		sprite_clips[ 0 ]->h = 100;

		sprite_clips[ 1 ]->x = 100;
		sprite_clips[ 1 ]->y = 0;
		sprite_clips[ 1 ]->w = 100;
		sprite_clips[ 1 ]->h = 100;

		sprite_clips[ 2 ]->x = 0;
		sprite_clips[ 2 ]->y = 100;
		sprite_clips[ 2 ]->w = 100;
		sprite_clips[ 2 ]->h = 100;

		sprite_clips[ 3 ]->x = 100;
		sprite_clips[ 3 ]->y = 100;
		sprite_clips[ 3 ]->w = 100;
		sprite_clips[ 3 ]->h = 100;
	}
	return success;
}
