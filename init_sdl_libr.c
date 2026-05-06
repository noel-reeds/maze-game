#include "main.h"
bool init_sdl_libr(void) {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
		printf("SDL could not initialize! SDL_Error: %s", SDL_GetError());
		success = false;
	}
	else {
		ctx->window = SDL_CreateWindow(
				"MAZE GAME!", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!ctx->window) {
			printf("Window could not be created! SDL_Error: %s",
					SDL_GetError());
			success = false;
		}
		else {
			ctx->rndr = SDL_CreateRenderer(
					ctx->window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!ctx->rndr) {
				printf("Renderer could not be created! "
						"SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(ctx->rndr, 0xFF, 0xFF, 0xFF, 0xFF);
				int img_flags = IMG_INIT_PNG;

				if (!(IMG_Init(img_flags) & img_flags)) {
					printf("SDL_image could not initialize! "
							"SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
							TTF_GetError());
					success = false;
				}
			}
		}
	}
	return (success);
}
