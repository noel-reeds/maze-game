#include "inc/headers.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void draw_stuff(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
	SDL_RenderClear(instance.renderer);
	SDL_SetRenderDrawColor(instance.renderer, 0, 0, 255, 255);

	SDL_Rect fillRect = {
				SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4,
				SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	SDL_RenderFillRect(instance.renderer, &fillRect);
}

int poll_events()
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;
			if (key.keysym.scancode == 0x29)
				return (1);
			break;
		}
	}
	return (0);
}
