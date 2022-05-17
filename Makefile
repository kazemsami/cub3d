# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahhammou <ahhammou@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 19:51:16 by kabusitt          #+#    #+#              #
#    Updated: 2022/05/16 17:11:17 by kabusitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = main.c free_mem.c draw.c draw2.c init_player.c key_hook.c key_hook2.c loadmap.c loadmap2.c loadmap3.c loadmap4.c loadmap5.c check_map.c check_map2.c
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
OS	= $(shell uname)

ifeq ($(OS), Linux)
	MLX_FLAGS = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
	MLX_PATH = mlx_linux
else
	MLX_FLAGS = -Lmlx_mac -lmlx -Imlx_mac -framework OpenGL -framework AppKit
	MLX_PATH = mlx_mac
endif

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${CFLAGS} ${OBJS} $(LIBFT) ${MLX_FLAGS} -o $@

%.o: %.c
	${MAKE} -C libft
	${CC} ${CFLAGS} -c $< -Llibft -lft ${MLX_FLAGS} -o $@

clean:
	rm -rf src/*.o
	${MAKE} clean -C libft

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C libft

re: fclean all
