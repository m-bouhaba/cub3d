SRC = main.c libft.c libft_2.c libft_3.c get_next_line.c parsing1.c parsing2.c \
	parsing3.c parsing4_map_check.c parsing5_check_new_line.c print_in_window.c \
	print_in_window2.c get_color.c dda.c dda_utils.c ./parsing/ft_splitt.c ./parsing/get_next_line_utils.c \
	./parsing/map_check_tools.c ./parsing/parsing_tools.c ./parsing/rgb_check.c \
	./parsing/get_full_map.c ./parsing/map_check_tools_2.c ./parsing/parsing_tools_2.c \
	./parsing/get_next_line.c ./parsing/parsing.c ./parsing/parsing_tools_3.c \
	./parsing/map_check.c ./parsing/path_check.c ./parsing/rgb_tools.c
cub3d = cub3d
SANITIZE = -g -fsanitize=address
FLAGS = -lmlx -lX11 -lXext -lm -lpthread -ldl -Wall -Wextra -Werror $(SANITIZE)
CC = cc

all : cub3d
$(cub3d): $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(cub3d)
	@tput setaf 2; echo "cub3d IS READY"

clean :
	@rm -f *.o
	@tput setaf 1; echo "CLEAN COMPLET" 

fclean : clean
	@rm -f cub3d
	@tput setaf 1; echo "FCLEAN COMPLET"
re: fclean all