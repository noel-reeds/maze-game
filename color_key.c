#include "main.h"

_Texture *foo_texture = NULL;
_Texture *bg_texture = NULL;

bool load_from_file(_Texture *T, const char *str_path)
{
	// free(&T);
	SDL_Texture *new_texture = NULL;
	SDL_Surface *surface = IMG_Load(str_path);
	
	if (!surface)
		printf("Unable to load image %s! SDL_image Error: %s\n",
				str_path, IMG_GetError());
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(
				surface->format, 0, 0xFF, 0xFF));
		new_texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (!new_texture)
			printf("Unable to create texture from %s! SDL Error: %s\n",
					str_path, SDL_GetError());
		else
		{
			T->width = surface->w;
			T->height = surface->h;
		}
		SDL_FreeSurface(surface);
	}
	T->m_texture = new_texture;
	return (T->m_texture != NULL);
}

void free_texture(_Texture *T)
{
	if (!T->m_texture)
	{
		SDL_DestroyTexture(T->m_texture);
		T->m_texture = NULL;
		T->width = 0;
		T->height = 0;
	}
}

void render(SDL_Renderer *R, _Texture *T, int x, int y)
{
	SDL_Rect render_quad = { x, y, T->width, T->height };
	SDL_RenderCopy(R, T->m_texture, NULL, &render_quad);
}

