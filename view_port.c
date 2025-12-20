#include "main.h"
/**
 * top_left_corner_viewport - Top left corner viewport
 *
 *Return: void
 */
void top_left_corner_viewport(void)
{
	SDL_Rect top_left;
	top_left.x = 0;
	top_left.y = 0;
	top_left.w = SCREEN_WIDTH / 2;
	top_left.h = SCREEN_WIDTH  / 2;
	SDL_RenderSetViewport(renderer, &top_left);
}
/**
 * top_right_corner_viewport - Top right viewport
 *
 *Return: void
 */
void top_right_corner_viewport(void)
{
	SDL_Rect top_right;
	top_right.x = SCREEN_WIDTH / 2;
	top_right.y = 0;
	top_right.w = SCREEN_WIDTH / 2;
	top_right.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(renderer, &top_right);
}
/**
 * bottom_viewport - Bottom viewport
 *
 *Return: void
 */
void bottom_centre_viewport(void)
{
	SDL_Rect bottom_viewport;
	bottom_viewport.x = 0;
	bottom_viewport.y = SCREEN_HEIGHT / 2;
	bottom_viewport.w = SCREEN_WIDTH;
	bottom_viewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(renderer, &bottom_viewport);
}
