#include "main.h"
#include "mouse.h"
/* scene textures */
_Texture *up;
_Texture *down;
_Texture *right;
_Texture *left;
_Texture *press;

void initialize_button(btt_e_handlr *self)
{
	self->pos.x = 0;
	self->pos.y = 0;
	self->current_sprite = BS_MOUSE_OUT;
}

void set_button_position(btt_e_handlr *self, int x, int y)
{
	self->pos.x = x;
	self->pos.y = y;
}

void handle_event(btt_e_handlr *self, SDL_Event *event)
{
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN ||	event->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;

		/* check if mouse is outside a button or not*/
		if (x < self->pos.x || x > self->pos.x + BUTTON_WIDTH)
			inside = false;
		else if (y < self->pos.y || y > self->pos.y + BUTTON_HEIGHT)
			inside = false;
		if (!inside)
			self->current_sprite = BS_MOUSE_OUT;
		else
		{
			switch(event->type)
			{
				case SDL_MOUSEMOTION:
				self->current_sprite = BS_MOUSE_OVER_MOTION;
				break;
				
				case SDL_MOUSEBUTTONDOWN:
				self->current_sprite = BS_MOUSE_DOWN;
				break;

				case SDL_MOUSEBUTTONUP:
				self->current_sprite = BS_MOUSE_UP;
				break;
			}
		}
	}
}

void button_render(btt_e_handlr *self)
{
	render(renderer, ss_texture, self->pos.x, self->pos.y, sprite_clips[self->current_sprite], 0.0, NULL, SDL_FLIP_NONE);
}
