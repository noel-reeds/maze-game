#ifndef _MAIN_H_
#define _MAIN_H_

/* screen dimension constants */
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define MAP_WIDTH 9
#define MAP_LENGTH 12
#define CELL_SIZE 16
#define NUM_RAYS 320
#define FOV (60 * M_PI / 180)
#define PLAYER_SIZE 3
#define PLAYER_SPEED 5
#define MAX_DEPTH 512

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
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

/* Key press surface constants */
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

/* game window initializations */
extern SDL_Surface *screenSurface;
extern SDL_Window *window;
extern SDL_Surface *KeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
extern SDL_Surface *currentSurface;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

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
bool load_media_surface(void);
void close_sdl(void);
SDL_Surface *load_surface(const char *surface_path);
SDL_Texture *load_texture(const char *image_path);
bool load_media_texture(void);

#endif
