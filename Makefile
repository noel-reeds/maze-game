# Compiles game with both gcc and sdl2 flags
OBJS = 

# specifies compiler
CC = gcc

# Compiler flags
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic

# Linker flags
LINKER_FLAGS = sdl2-config --cflags --libs

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 06_extension_libraries_and_loading_other_image_formats

# Target that compiles our executable
all:
