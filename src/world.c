#include "../inc/main.h"
/**
 * draw_map - constructs 2D different wall types determined by value 1-2
 * @instance: encapsulates SDL window and renderer pointers
 * Return: void
*/

int map[MAP_WIDTH][MAP_LENGTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 2, 2, 0, 0, 0, 2, 2, 2, 0, 1},
	{1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 2, 2, 0, 0, 0, 2, 2, 0, 0, 1},
	{1, 0, 2, 0, 0, 3, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void draw_map(SDL_Instance *instance)
{
	int x, y;

	for (y = 0; y < MAP_LENGTH ; y++)
	{
		for (x = 0; x < MAP_LENGTH; x++)
		{
			if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 3)
			{
				SDL_Rect wall = {x * CELL_SIZE, y * CELL_SIZE,
					CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(
					instance->renderer, 0, 0, 0, 0);
				SDL_RenderFillRect(instance->renderer, &wall);
			}
		}
	}
}

/**
 * collision_detection - users the player stays within the walls of the map,
 *	and does not collide with objects
 * @x: horizontal grid line
 * @y: vertical grid line
 * Return: return 0 to indicate the player is within the boarder spaces
*/
int collision_detection(int x, int y)
{
	int map_x1, map_y1;

	if (x < 0 || x + PLAYER_SIZE > SCREEN_WIDTH || y < 0 ||
		y + PLAYER_SIZE > SCREEN_HEIGHT)
	{
		return (1);
	}

	map_x1 = x / CELL_SIZE;
	map_y1 = y / CELL_SIZE;

	if (map[map_y1][map_x1] != 0)
	{
		return (1);
	}
	return (0);
}
