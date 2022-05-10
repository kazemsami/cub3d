# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 19:51:16 by kabusitt          #+#    #+#              #
#    Updated: 2022/05/09 14:41:08 by kabusitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = main.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c philosophers.h
	${CC} ${CFLAGS} -c $< -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
