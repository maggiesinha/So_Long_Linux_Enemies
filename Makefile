# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 14:46:34 by mvalerio          #+#    #+#              #
#    Updated: 2023/10/30 10:52:00 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/main.c src/map_check.c src/map.c src/move_utils.c src/move.c \
src/pictures.c src/utils.c src/flood_fill.c src/enemies.c src/enemy_motion.c \
src/rendering_player.c

OBJS = $(SRC:.c=.o)

MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz minilibx/libmlx.a

LIBFT = libs/libft

LIBFTA = libs/libft/libft.a

MINILIBX = minilibx

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SRC) $(LIBFTA) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make clean -C $(MINILIBX)
	make fclean -C $(LIBFT)
	rm -rf libmlx.a

re: fclean
	make
