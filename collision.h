#ifndef _COLLISION_H_
#define _COLLISION_H_
#include "main.h"

typedef struct player_collision
{
	int pos_x, pos_y;
	int vel_x, vel_y;
	SDL_Rect collider;
	int p8_width;
	int p8_height;
	int p8_velocity;
} collision_handlr;

extern collision_handlr player8;

void init_var(collision_handlr *self);
void ajusts_player_speed(collision_handlr *self, SDL_Event e);
void move_player(collision_handlr *self, SDL_Rect wall);
bool check_collision(collision_handlr *self, SDL_Rect a, SDL_Rect b);
void handle_keyboard_event(collision_handlr *self, SDL_Event e);


#endif
