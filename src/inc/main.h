#ifndef _DEMO_H_
#define _DEMO_H_

#define SCREEN_WIDTH 1260
#define SCREEN_HEIGHT 720
#define MAP_SIZE 8
#define TILE_SIZE 64
#define NUM_RAYS 320
#define FOV (60 * M_PI / 180)

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/*--------------Draw Stuff--------------*/
typedef struct
{
	float x, y;
	float angle;
} Player;
/*--------------Player--------------*/

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance instance);
int poll_events();
void draw_map(SDL_Instance *instance);
#endif
