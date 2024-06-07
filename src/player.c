#include "../inc/main.h"
/**
 * draw_stuff - render a random stuff
 *
 *@instance: SDL instance.
 *
 * Return: returns void
 */

void create_player(SDL_Instance *instance, Player *player)
{ 
	SDL_Rect player_rect = {player->px, player->py, PLAYER_SIZE, PLAYER_SIZE};
	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(instance->renderer, &player_rect);
}
