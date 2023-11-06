# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 14:46:34 by mvalerio          #+#    #+#              #
#    Updated: 2023/11/06 11:57:25 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/death.c src/end_program1.c src/end_program2.c \
src/enemies_set_directions.c src/enemies1.c src/enemies2.c src/flood_fill.c \
src/keys.c src/map1.c src/map2.c src/pictures.c src/player1.c src/player2.c \
src/rendering1.c src/rendering2.c src/main.c

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
