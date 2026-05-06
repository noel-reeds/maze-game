#include "main.h"
/**
 * load_media_surface - loads media to render.
 *
 * Return: true or false
 */
bool load_media_surface(void)
{
	/* loading success flag */
	bool success = true;
	if (load_from_file(texture, "collision_detection/dot.bmp"))
		success = true;
	else
		success = false;
	return (success);
}
/**
 * loadSurface - load image at specified path
 *
 *@surface_path: image path
 *
 * Return: SDL_Surface
 */
SDL_Surface *load_surface(const char *surface_path)
{
	/* The final optimized image */
	SDL_Surface *optimized_surface = NULL;
	/* load image at specified path */
	SDL_Surface *loaded_surface = IMG_Load(surface_path);

	if (!loaded_surface)
	{
		printf("unable to load image %s! SDL Error: %s\n",
				surface_path, IMG_GetError());
	}
	else
	{
		/* convert surface to screen format */
		optimized_surface = SDL_ConvertSurface(
								loaded_surface,
								screenSurface->format,
								0);
		if (!optimized_surface)
		{
			printf("unable to optimize image %s! SDL Error: %s\n",
					surface_path, SDL_GetError());
		}
		/* remove old loaded surface */
		SDL_FreeSurface(loaded_surface);
	}
	return (optimized_surface);
}
