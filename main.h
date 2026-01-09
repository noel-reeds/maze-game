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
#define WALKING_ANIMATION_FRAMES 4

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
	SDL_Texture *m_texture;
	int width;
	int height;
} _Texture;

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
extern SDL_Surface *currentSurface;
extern SDL_Surface *KeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern _Texture *foo_texture;
extern _Texture *bg_texture;

extern SDL_Rect *sprite_clips[ WALKING_ANIMATION_FRAMES ];
extern _Texture *ss_texture;

extern _Texture *mod_texture;
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
void render_red_filled_quad(void);
void render_green_outlined_quad(void);
void draw_blue_horizontal_line(void);
void vertical_dotted_line(void);
void top_left_corner_viewport(void);
void top_right_corner_viewport(void);
void bottom_centre_viewport(void);
bool load_from_file(_Texture *T, const char *str_path);
void free_texture(_Texture *T);
void set_color(uint8_t red, uint8_t green, uint8_t blue);
void set_color(uint8_t red, uint8_t green, uint8_t blue);
void set_blend_mode(SDL_Texture *Texture, SDL_BlendMode blending);
void set_alpha(uint8_t alpha);
void render(SDL_Renderer *R, _Texture *T, int x, int y, SDL_Rect *_clip);

#endif
