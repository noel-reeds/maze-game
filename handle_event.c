#include "main.h"
#include "collision.h"

void handle_keyboard_event(collision_handlr *self, SDL_Event event_e)
{
	if (event_e.type == SDL_KEYDOWN && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_x -= self->p8_velocity;
			break;

			case SDLK_s:
			self->vel_x += self->p8_velocity;
			break;

			case SDLK_a:
			self->vel_y -= self->p8_velocity;
			break;

			case SDLK_d:
			self->vel_y += self->p8_velocity;
			break;
		}
	}
	else if (event_e.type == SDL_KEYUP && event_e.key.repeat == 0)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_x += self->p8_velocity;
			break;

			case SDLK_s:
			self->vel_x -= self->p8_velocity;
			break;

			case SDLK_a:
			self->vel_y += self->p8_velocity;
			break;

			case SDLK_d:
			self->vel_y -= self->p8_velocity;
			break;
		}
	}
}
