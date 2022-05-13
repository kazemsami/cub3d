# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 19:51:16 by kabusitt          #+#    #+#              #
#    Updated: 2022/05/13 18:25:09 by kabusitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = main.c free_mem.c loadmap.c loadmap2.c loadmap3.c loadmap4.c loadmap5.c check_map.c check_map2.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c philosophers.h
	${MAKE} -C libft
	${CC} ${CFLAGS} -c $< -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	rm -f *.o
	${MAKE} clean -C libft

fclean: clean
	rm -f ${NAME}
	${MAKE} fclean -C libft

re: fclean all
