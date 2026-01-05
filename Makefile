SRC = main.c libft.c libft_2.c libft_3.c get_next_line.c parsing1.c parsing2.c \
	parsing3.c parsing4_map_check.c parsing5_check_new_line.c print_in_window.c \
	print_in_window2.c get_color.c dda.c dda_utils.c ./parsing/ft_splitt.c ./parsing/get_next_line_utils.c \
	./parsing/map_check_tools.c ./parsing/parsing_tools.c ./parsing/rgb_check.c \
	./parsing/get_full_map.c ./parsing/map_check_tools_2.c ./parsing/parsing_tools_2.c \
	./parsing/get_next_line.c ./parsing/parsing.c ./parsing/parsing_tools_3.c \
	./parsing/map_check.c ./parsing/path_check.c ./parsing/rgb_tools.c
cub3d = cub3d
SANITIZE = -g -fsanitize=address

# Allow per-machine MinilibX installs. Example:
# make INC_DIR=$HOME/local/include LIB_DIR=$HOME/local/lib
INC_DIR ?= /usr/local/include
LIB_DIR ?= /usr/local/lib

# Compiler and linker flags. Use CFLAGS when compiling, LDFLAGS when linking.
CC = cc
CFLAGS ?= -Wall -Wextra -I$(INC_DIR) $(SANITIZE)
LDFLAGS ?= -L$(LIB_DIR) -lmlx -lX11 -lXext -lm -lpthread -ldl

all : cub3d
$(cub3d): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(cub3d)
	@tput setaf 2; echo "cub3d IS READY"

clean :
	@rm -f *.o
	@tput setaf 1; echo "CLEAN COMPLET" 

fclean : clean
	@rm -f cub3d
	@tput setaf 1; echo "FCLEAN COMPLET"
re: fclean all