NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -IGNL -std=gnu17 -I. -I./mlx
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lz
RM = rm -f

SRCS =  main.c \
		setup/setup_master_struct.c \
		parsing/check_duplicates.c \
		parsing/open_xpm_files.c \
		parsing/parse_cub_file.c \
		parsing/parse_grid_map.c \
		parsing/parse_RGB.c \
		parsing/parse_textures.c \
		end_program/free_memory.c \
		end_program/parse_failure.c \
		window_management/render_window.c \
		window_management/hooks_closing.c \
		raycasting/player_direction.c \
		raycasting/raycasting.c \
		raycasting/render_rays.c \
		raycasting/texture_rendering.c \
		movement/player_movement.c \
		toolbox/helper_functions_00.c \
		toolbox/helper_functions_01.c \
		toolbox/helper_functions_02.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		minimap/minimap.c \
		

OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	@make -C mlx CC="cc -std=gnu17" 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean
	make -C mlx clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C mlx clean

re: fclean all

.PHONY: all clean fclean re
