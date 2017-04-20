NAME=42gl
LIB=gl.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lmlx -framework OpenGL -framework AppKit
SRC=data.c main.c
OBJ=$(SRC:.c=.o)

SRC_D=./srcs/
INC_D=./includes/

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -c $(M) $(addprefix $(SRC_D), $(SRC)) -I $(INC_D) -L libtf/ -lft
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) 

clean:
	@echo "Cleaning."
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
