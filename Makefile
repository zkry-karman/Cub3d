NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./mlx
MLXFLAGS = -L./mlx -lmlx -lXext -lX11 -lm -lz
RM = rm -f

SRCS = main.c render_window.c
OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	@make -C mlx CC="cc -std=gnu17" 
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

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
