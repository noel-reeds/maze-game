#include "main.h"
#include "collision.h"

int main(void)
{
	texture = malloc(sizeof(_Texture));
	ctx = malloc(sizeof(SDL_Context));

	init_var(&player8);
	if (!init_sdl_libr()){
		printf("Failed to initialize!\n");
	}
	else {
		if (!load_media_surface()) {
			printf("Failed to load media!\n");
		}
		else {
			SDL_Event event_e;
			bool quit = false;
			SDL_Rect wall = { 300, 40, 40, 400 };

			while (!quit) {
				while (SDL_PollEvent(&event_e) != 0) {
					if (event_e.type == SDL_QUIT)
						quit = true;
					handle_keyboard_event(&player8, event_e);
				}	
				SDL_SetRenderDrawColor(ctx->rndr, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(ctx->rndr);
				render(ctx->rndr, texture,
						0, 0, NULL, 0.0, NULL, SDL_FLIP_NONE);

				SDL_SetRenderDrawColor(ctx->rndr, 0xFF, 0x00, 0x00, 0x00);
				SDL_RenderFillRect(ctx->rndr, &wall);
				SDL_RenderPresent(ctx->rndr);
			}
		}
		SDL_Log("Event queue is empty.");
		close_sdl();
	}
	return (0);
}
