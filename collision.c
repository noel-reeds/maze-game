#include "main.h"
#include "collision.h"

collision_handlr player8;

void init_var(collision_handlr *self) {
	self->p8_width = 20;
	self->p8_height = 20;
	self->p8_velocity = 10;
	
	self->pos_x = 0;
	self->pos_y = 0;

	self->collider.w = self->p8_width;
	self->collider.h = self->p8_height;

	self->vel_x = 0;
	self->vel_y = 0;
}

void move_player(collision_handlr *self, SDL_Rect wall) {
	self->pos_x += self->vel_x;
	self->collider.y = self->pos_x;

	if (self->pos_x < 0 || self->pos_x + self->p8_width > SCREEN_WIDTH ||
				check_collision(self, self->collider, wall)) {
		self->pos_x -= self->vel_x;
		self->collider.y = self->pos_x;
	}
	self->pos_y += self->vel_y;
	self->collider.x = self->pos_y;
	if (self->pos_y < 0 || self->pos_y + self->p8_height > SCREEN_HEIGHT ||
				check_collision(self, self->collider, wall)) {
		self->pos_y -= self->vel_y;
		self->collider.x = self->pos_y;
	}
}

bool check_collision(collision_handlr *self, SDL_Rect a, SDL_Rect b) {
	(void)self;
	/* coordinates of two collision boxes */
	int left_a, right_a, top_a, bottom_a;
	int left_b, right_b, top_b, bottom_b;

	/* left rect coordinates */
	left_a = a.x;
	right_a = a.x + a.w;
	top_a = a.y;
	bottom_a = a.y + a.h;

	/* right rect coordinates */
	left_b = b.x;
	right_b = left_b + b.w;
	top_b = b.y;
	bottom_b = b.y + b.h;

	if (bottom_a <= top_b && right_a <= left_b)
		return false;
	if (top_a >= bottom_b)
		return false;
	if (right_a <= left_a)
		return false;
	if (left_a >= right_b)
		return false;
	return true;
}
