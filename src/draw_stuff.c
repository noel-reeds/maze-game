#include "inc/main.h"
/**
 * draw_stuff - render a random stuff
 *
 *@instance: SDL instance.
 *
 * Return: returns void
 */
int map[MAP_SIZE][MAP_SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
};

//Player player = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0};

void draw_map(SDL_Instance *instance)
{
        int x, y;

        for (y = 0; y < MAP_SIZE; y++)
        {
                for (x = 0; x < MAP_SIZE; x++)
                {
                        if (map[y][x] == 1)
                        {
                                SDL_Rect wall = {x * TILE_SIZE, y * TILE_SIZE,
                                        TILE_SIZE, TILE_SIZE};
                                SDL_SetRenderDrawColor(
                                        instance->renderer, 200, 200, 200, 255);
                                SDL_RenderFillRect(instance->renderer, &wall);
                        }
                }
        }
}
