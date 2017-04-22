NAME=fdf

LIB=gl.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lmlx -framework OpenGL -framework AppKit
MLX=minilibx_macos
GNL=./gnl
FT=./libft
ifeq ("$t", "true")
LIBS +=-L $(MLX) -l mlx -I minilibx_macos
endif
# SRC=data.c main.c displays.c parsing.c vertice.c
SRC=data.c\
    displays.c\
    main.c\
    parsing.c\
    pixel.c\
    utils.c\
    vertice.c
OBJ=$(SRC:.c=.o)

SRC_D=./srcs/
INC_D=./includes/

$(NAME):
	make -C $(FT)/
	make -C $(GNL)/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(GNL)/get_next_line.o -o $(NAME) -Llibft/ -Ilibft -lft


all: $(NAME)

clean:
	@echo "Cleaning."
	make -C $(FT)/ clean
	make -C $(GNL)/ clean
	rm -f $(OBJ)

fclean: clean
	make -C $(FT)/ fclean
	make -C $(GNL)/ fclean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all
