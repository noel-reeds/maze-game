#include "main.h"
/**
 * create_player - creates a player in a field
 *
 *@instance: SDL instance.
 *
 *@player: a player in a battle.
 *
 * Return: returns void
 */

void create_player(SDL_Instance *instance, Player *player)
{
	SDL_Rect player_rect = {player->px, player->py, PLAYER_SIZE, PLAYER_SIZE};

	SDL_SetRenderDrawColor(instance->renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(instance->renderer, &player_rect);
}
