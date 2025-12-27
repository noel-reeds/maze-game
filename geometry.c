#include "main.h"
/**
 * render_red_filled_quad - Render red filled quad
 *
 *Return: void
 */
void render_red_filled_quad(void)
{
	SDL_Rect quad = {
		SCREEN_WIDTH / 4,
		SCREEN_HEIGHT / 4,
		SCREEN_WIDTH / 2,
		SCREEN_HEIGHT / 2
	};
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &quad);
}

/**
 * render_green_outlined_quad - Render green outlined quad
 *
 *Return: void
 */
void render_green_outlined_quad(void)
{
	SDL_Rect quad = {
		SCREEN_WIDTH / 6,
		SCREEN_HEIGHT / 6,
		SCREEN_WIDTH * 2 / 3,
		SCREEN_HEIGHT * 2 / 3
	};
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, &quad);
}
/**
 * draw_blue_horizontal_line - Draw blue horizontal line
 *
 *Return: void
 */
void draw_blue_horizontal_line(void)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0XFF);
	SDL_RenderDrawLine(renderer, 0,
			SCREEN_HEIGHT / 2,
			SCREEN_WIDTH,
			SCREEN_HEIGHT / 2);
}

/**
 * vertical_dotted_line - Draw vertical line of yellow dots
 *
 *Return: void
 */
void vertical_dotted_line(void)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	{
		SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
	}
}
