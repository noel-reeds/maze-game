#include "inc/headers.h"

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	while ("Battle Snipper")
        {
                SDL_SetRenderDrawColor(instance.renderer,  0, 128, 0, 0);
                SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(instance);
                SDL_RenderPresent(instance.renderer);
        }

        SDL_DestroyRenderer(instance.renderer);
        SDL_DestroyWindow(instance.window);
        SDL_Quit();
        return (0);
}
