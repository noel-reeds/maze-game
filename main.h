#ifndef _DEMO_H_
#define _DEMO_H_

/* screen dimension constants */
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 510
*/
#define MAP_WIDTH 9
#define MAP_LENGTH 12
#define CELL_SIZE 16
#define NUM_RAYS 320
#define FOV (60 * M_PI / 180)
#define PLAYER_SIZE 3
#define PLAYER_SPEED 5
#define MAX_DEPTH 512

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


typedef struct
{
	float px, py;
	float pa;
} Player;

typedef struct {
	float x, y;
	float intensity;
} Light;

extern int map[MAP_WIDTH][MAP_LENGTH];

int init_instance(SDL_Instance *);
int poll_events(Player *player);
void draw_map(SDL_Instance *instance);
void render_rays(SDL_Instance *instance);
void create_player(SDL_Instance *instance, Player *player);
int collision_detection(int x, int y);
void render_3d_walls(SDL_Instance *instance, Player *player, Light *lights, int num_lights);
float calculate_light_intensity(float x, float y, Light *lights, int num_lights);

bool initialize_sdl(void);
bool loading_media(void);
void close_sdl(void);

#endif
