#include "main.h"
#include "collision.h"

void handle_keyboard_event(collision_handlr *self, SDL_Event event_e)
{
	if (event_e.type == SDL_KEYDOWN)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_y -= self->p8_velocity; 
			break;

			case SDLK_s:
			self->vel_y += self->p8_velocity;
			break;

			case SDLK_d:
			self->vel_x += self->p8_velocity;
			break;

			case SDLK_a:
			self->vel_x -= self->p8_velocity;
			break;
		}
	}
	if (event_e.type == SDL_KEYUP)
	{
		switch(event_e.key.keysym.sym)
		{
			case SDLK_w:
			self->vel_y -= self->p8_velocity;
			break;

			case SDLK_s:
			self->vel_y += self->p8_velocity;
			break;

			case SDLK_d:
			self->vel_x += self->p8_velocity;
			break;

			case SDLK_a:
			self->vel_x -= self->p8_velocity;
			break;
		}
	}
	if (self->pos_x > SCREEN_WIDTH - self->p8_width)
        self->pos_x = SCREEN_WIDTH - self->p8_width;
    if (self->pos_y > SCREEN_HEIGHT - self->p8_width)
        self->pos_y = SCREEN_HEIGHT - self->p8_width;
    if (self->pos_y < 0)
        self->pos_y = 0;
    if (self->pos_x < 0)
        self->pos_x = 0;
}
