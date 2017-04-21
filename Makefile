NAME=fdf
LIB=gl.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lmlx -framework OpenGL -framework AppKit
SRC=data.c main.c
OBJ=$(SRC:.c=.o)

SRC_D=./srcs/
INC_D=./includes/

$(NAME):
	make -C ./libft/
	make -C ./gnl/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) ./gnl/get_next_line.o -o $(NAME) -Llibft/ -Ilibft -lft


all: $(NAME)

clean:
	@echo "Cleaning."
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
