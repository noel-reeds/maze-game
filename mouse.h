#ifndef _MOUSE_H_
#define _MOUSE_H_
#include "main.h"

typedef struct button_event_handler
{
	enum ButtonSprite current_sprite;
	SDL_Point pos;
} btt_e_handlr;

/* game window initializations */
extern btt_e_handlr buttons[ TOTAL_BUTTONS ];

void button_render(btt_e_handlr *self);
void initialize_button(btt_e_handlr *self);
void set_button_position(btt_e_handlr *self, int x, int y);
void handle_event(btt_e_handlr *self, SDL_Event *event);

#endif
