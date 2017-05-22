# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbastion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/17 13:48:19 by vbastion          #+#    #+#              #
#    Updated: 2017/05/22 11:57:22 by vbastion         ###   ########.fr        #
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
	@echo "\033[33mBuilding fdf executable.\033[0m"
	$(CC) $(CFLAGS) $? -o $(NAME) -L ${FT}/ -lft  $(LIBS)
	@echo "\033[32mDone building FdF!\033[0m"

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(FT)

all: $(NAME)

clean:
	@echo "\033[31mCleaning FdF\033[0m"
	/bin/rm -f $(OBJ)
	/bin/rm -f $(ITEM)
	@make -C $(FT) clean

fclean: clean
	@echo "\033[31mFCleaning FdF\033\0m"
	/bin/rm -f $(NAME)
	make -C $(FT) fclean

re: fclean all
