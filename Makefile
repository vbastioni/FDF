# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbastion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 13:48:19 by vbastion          #+#    #+#              #
#    Updated: 2017/05/22 10:30:04 by vbastion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
LIB=fdf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
FT=./libft
LIBS=-lmlx -framework OpenGL -framework AppKit
INCS=-I ${INC_D} -I ${FT}
SRC_D=./srcs/
INC_D=./includes/
ITEM:=\
	callback.o\
	callback_p2.o\
	color.o\
	draw_iso.o\
	draw_iso_p2.o\
	error.o\
	img.o\
	main.o\
	parsing.o
OBJ:= $(addprefix ./src/, $(ITEM))

$(NAME):
	make -C $(FT)
	gcc -c $(OBJ:.o=.c) $(CFLAGS) -I ${FT}
	$(CC) $(ITEM) -o $(NAME) -L ${FT}/ -lft  $(LIBS)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(ITEM)
	make -C $(FT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(FT) fclean

re: fclean all
