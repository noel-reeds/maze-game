#include "main.h"
ButtonSprite current_sprite;
ButtonSprite buttons[ TOTAL_BUTTONS ];
SDL_Point pos;

void initialize_button(void)
{
	pos.x = 0;
	pos.y = 0;
	current_sprite = BS_MOUSE_OUT;
}

void set_button_position(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

void handle_event(SDL_Event *event)
{
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN ||			event->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;

		/* check if mouse is outside a button or not*/
		if (x < pos.x || x > pos.x + BUTTON_WIDTH)
			inside = false;
		else if (y < pos.y || y > pos.y + BUTTON_HEIGHT)
			inside = false;
		if (!inside)
			current_sprite = BS_MOUSE_OUT;
		else
		{
			switch(event->type)
			{
				case SDL_MOUSEMOTION:
				current_sprite = BS_MOUSE_OVER_MOTION;
				break;
				
				case SDL_MOUSEBUTTONDOWN:
				current_sprite = BS_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				current_sprite = BS_MOUSE_UP;
				break;
			}
		}
	}
}

void button_render(void)
{
	render(renderer, ss_texture, pos.x, pos.y,
			&sprite_clips[current_sprite], NULL, NULL, SDL_FLIP_NONE);
}
