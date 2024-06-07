#include "../inc/main.h"
/**
 * calculate_light_intensity - calculates increase in light intensity per each
 *	direction along the x, y axis
 * @x: x-axis on the map
 * @y: y-axis on the map
 * @lights: lines of lights to be rendered
 * @num_lights: number of lights
 * Return: intensity of float data type
*/
float calculate_light_intensity(float x, float y, Light *lights, int num_lights)
{
	float intensity = 0.0f, distance;
	int i;

	for (i = 0; i < num_lights; i++)
	{
		distance = sqrtf(powf(lights[i].x - x, 2) + powf(lights[i].y - y, 2));
		if (distance < 1.0f) distance = 1.0f;
		intensity += lights[i].intensity / (distance * distance);
	}
	if (intensity > 1.0f) intensity = 1.0f;
	return intensity;
}
/**
 * render_3d_walls - c
 * @instance: pointer to window and renderer struct
 * @player: pointer to players attributes
 * @lights: pointer to light directions
 * @num_lights: number of lights
 * Return: void
*/
void render_3d_walls(SDL_Instance *instance, Player *player, Light *lights, int num_lights)
{
	int plane_width, i, hit_wall, wall_type, mapX, mapY, ceiling, floor_height;
	float ray_angle, distance_to_wall, rayDirX, rayDirY, wall_x, wall_y, light_intensity;

	plane_width = SCREEN_WIDTH / NUM_RAYS;

	for (i = 0; i < NUM_RAYS; i++)
	{
		ray_angle = player->pa - FOV / 2 + i * (FOV / NUM_RAYS);
		distance_to_wall = 0;
		hit_wall = 0;
		wall_type = 0;

		rayDirX = cos(ray_angle);
		rayDirY = sin(ray_angle);

		while (!hit_wall && distance_to_wall < MAX_DEPTH)
		{
			distance_to_wall += 0.1f;
        		mapX = (player->px + rayDirX * distance_to_wall) / CELL_SIZE;
			mapY = (player->py + rayDirY * distance_to_wall) / CELL_SIZE;

			if (mapX < 0 || mapY >= MAP_LENGTH || mapY < 0 || mapY >= MAP_WIDTH)
			{
				hit_wall = 1;
				distance_to_wall = MAX_DEPTH;
			}
 
			else if (map[mapY][mapX] > 0)
			{
				hit_wall = 1;
				wall_type = map[mapY][mapX];
			}
 		}


		SDL_SetRenderDrawColor(instance->renderer, 0, 128, 0, 255);
		SDL_RenderDrawLine(instance->renderer, player->px, player->py,
			player->px + rayDirX * distance_to_wall, player->py + rayDirY * distance_to_wall);

		ceiling = (SCREEN_HEIGHT / 2.0) - SCREEN_HEIGHT / (distance_to_wall);
		SDL_SetRenderDrawColor(instance->renderer, 173, 216, 250, 255);
                SDL_Rect ceiling_rect = {i * plane_width, 0, plane_width, ceiling};
                SDL_RenderFillRect(instance->renderer, &ceiling_rect);

		floor_height = SCREEN_HEIGHT - ceiling;
		SDL_SetRenderDrawColor(instance->renderer, 0, 128, 0, 255);
                SDL_Rect floor_rect = {i * plane_width, floor_height, plane_width, SCREEN_HEIGHT - floor_height};
                SDL_RenderFillRect(instance->renderer, &floor_rect);

		wall_x = player->px + rayDirX * distance_to_wall;
		wall_y = player->py + rayDirY * distance_to_wall;

		light_intensity = calculate_light_intensity(wall_x, wall_y, lights, num_lights);
		if (light_intensity < 0.2f) light_intensity = 0.2f;

		Uint8 red, green, blue;
		switch (wall_type)
		{
			case 1:
				red = 255;
				green = 0;
				blue = 0;
				break;
			case 2:
				red = 210;
				green = 180;
				blue = 140;
				break;
			case 3:
				red = 0;
				green = 0;
				blue = 255;
				break;
			default:
				red = 255;
				green = 255;
				blue = 255;
				break;
		}

		red = (Uint8)(red * light_intensity);
		green = (Uint8)(green * light_intensity);
		blue = (Uint8)(blue * light_intensity);

		SDL_SetRenderDrawColor(instance->renderer, red, green, blue, 255);

		SDL_Rect wall_rect = {i * plane_width, ceiling, plane_width, floor_height - ceiling};
		SDL_RenderFillRect(instance->renderer, &wall_rect);
	}
}
