#include "main.h"
TTF_Font *font = NULL;
_Texture *ss_texture = NULL;
SDL_Rect *sprite_clips[ WALKING_ANIMATION_FRAMES ];
_Texture *mod_texture;
/**
 * load_from_file - loads image texture.
 *
 *@T: image texture
 *
 *@str_path: image path
 *
 *Return: bool.
 */
bool load_from_file(_Texture *T, const char *str_path)
{
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

void render(SDL_Renderer *R, _Texture *T,
				int x, int y, SDL_Rect *clip, double angle,
				SDL_Point *center, SDL_RendererFlip flip)
{
	SDL_Rect rect = {x, y, T->width, T->height};

	if (clip)
	{
		rect.w = clip->w;
		rect.h = clip->h;
	}
	SDL_RenderCopyEx(R, T->m_texture, clip, &rect,
			angle, center, flip);
}

bool load_from_rendered_text(char const *texture_text, SDL_Color text_color)
{
	free_texture(ss_texture);
	SDL_Surface *text_surface = TTF_RenderText_Blended(font,
									texture_text, text_color);

	if (!text_surface)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n",
				TTF_GetError());
	}
	else
	{
		ss_texture->m_texture = SDL_CreateTextureFromSurface(
									renderer, text_surface);
		if (ss_texture->m_texture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL_GetError: %s\n", SDL_GetError());
		}
		else
		{
			ss_texture->width = text_surface->w;
			ss_texture->height = text_surface->h;
		}
		SDL_FreeSurface(text_surface);
	}
	return ss_texture->m_texture != NULL;
}
