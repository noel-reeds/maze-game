#include "main.h"
SDL_Texture *foo_texture = NULL;
SDL_Texture *bg_texture = NULL;

SDL_Texture *m_texture = NULL;
int width = 0;
int height = 0;

bool load_from_file(const char *str_path)
{
	free();
	SDL_Texture *new_texture = NULL;
	SDL_Surface *surface = IMG_Load(str_path);
	
	if (!surface)
		printf("Unable to load image %s! SDL_image Error: %s\n",
				str_path, IMG_GetError());
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(
				loaded_surface->format, 0, 0xFF, 0xFF));
		new_texture = SDL_CreateTextureFromSurface(renderer, surface);
		if (!new_texture)
			printf("Unable to create texture from %s! SDL Error: %s\n",
					str_path, SDL_GetError());
		else
		{
			width = surface->w;
			height = surface->h;
		}
		SDL_FreeSurface(surface);
	}
	m_texture = new_texture;
	return (m_texture != NULL);
}

void free(void)
{
	if (!m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		width = 0;
		height = 0;
	}
}

void render(SDL_Texture *r_texture, int x, int y)
{
	SDL_Rect render_quad(x, y, width, height);
	SDL_RenderCopy(renderer, r_texture, NULL, &render_quad);
}

