# Header and C source files
src := $(wildcard *.c) $(wildcard *.h)

# Program for compiling C programs
cc := gcc

# Extra flags to pass to C compiler
cflags := -g -Wall -Werror -Wextra -pedantic -fsanitize=address,leak

# Extra SDL2 flags
sdl2_f := `sdl2-config --cflags --libs`
sdl2_i := -lSDL2_image
sdl2_ttf := -lSDL2_ttf

maze_r: $(src)
	$(cc) $(cflags) $(src) -o $@ $(sdl2_f) $(sdl2_i) $(sdl2_ttf)
