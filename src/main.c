#include "inc/main.h"
/**
 * main - entry point of a C program
 * Return: returns 0 on success
 */
int main( int argc, char* argv[] )
{
        SDL_Instance instance;

        if (init_instance(&instance) != 0)
                return (1);

        while ("Battle Snipper")
        {
                SDL_SetRenderDrawColor(instance.renderer,  0, 0, 255, 255);
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
