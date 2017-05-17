# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbastion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 13:48:19 by vbastion          #+#    #+#              #
#    Updated: 2017/05/17 16:15:34 by vbastion         ###   ########.fr        #
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

$(NAME): $(OBJ)
	make -C $(FT)
	$(CC) $? -o $(NAME) -L ${FT}/ -lft  $(LIBS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(FT)

clean:
	/bin/rm -f $(OBJ)
	make -C $(FT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(FT) fclean

re: fclean all
