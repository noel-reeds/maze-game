#include "main.h"
/**
 * main - main loop of SDL program
 * Return: returns 0 on success
 */

int main(void)
{
	SDL_Instance instance;
	Player player = {MAP_LENGTH / 2 * CELL_SIZE, MAP_WIDTH / 2 * CELL_SIZE, 0};
	int num_lights;

	if (init_instance(&instance) != 0)
		return (1);

	Light lights[] = {
		{MAP_LENGTH / 2 * CELL_SIZE, MAP_WIDTH / 2 * CELL_SIZE, 1.0f},
		{CELL_SIZE * 3, CELL_SIZE * 3, 0.5f}
	};

	num_lights = sizeof(lights) / sizeof(lights[0]);

	while ("Battle Snipper")
	{
		SDL_SetRenderDrawColor(instance.renderer,  40, 40, 40, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&player) == 1)
			break;

		render_3d_walls(&instance, &player, lights, num_lights);
		draw_map(&instance);
		create_player(&instance, &player);
		SDL_RenderPresent(instance.renderer);
	}

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
