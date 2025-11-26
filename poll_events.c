#include "main.h"
/**
 * poll_events - handles user input through event loop from the SDL event queue
 * @player: pointer that access players attributes on Player struct
 * Return: returns 0 on success, otherwise err.
 */
int poll_events(Player *player)
{
	SDL_Event event;
	int new_px, new_py;
	float angle;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return (1); }
		if (event.type == SDL_KEYDOWN)
		{
			new_px = player->px;
			new_py = player->py;
			angle = player->pa;

			if (event.key.keysym.sym == 'w')
				new_py -= PLAYER_SPEED;
			else if (event.key.keysym.sym == 's')
				new_py += PLAYER_SPEED;
			else if (event.key.keysym.sym == 'a')
				new_px -= PLAYER_SPEED;
			else if (event.key.keysym.sym == 'd')
				new_px += PLAYER_SPEED;
			else if (event.key.keysym.sym == 'q')
				angle -= 1;
			else if (event.key.keysym.sym == 'e')
				angle += 1;
			else if (event.key.keysym.sym == 0x1B)
				return (1);

			if (!collision_detection(new_px, new_py))
			{
				player->px = new_px;
				player->py = new_py;
				player->pa = angle;
			}
		}
	}

	return (0);
}
