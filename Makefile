NAME=fdf

LIB=gl.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lmlx -framework OpenGL -framework AppKit
MLX=minilibx_macos
GNL=./gnl
FT=./libft
ifeq ("$t", "true")
LIBS +=-L $(MLX) -l mlx -I $(MLX)
endif
SRC_D=./srcs/
INC_D=./includes/
ITEM:=\
    board.c\
    callback.c\
    color.c\
    data.c\
    dims.c\
    displays.c\
    img_data.c\
    main.c\
    parsing.c\
    pixel.c\
    utils.c\
    vertice.c
SRC:=$(addprefix $(SRC_D), $(ITEM))
OBJ:=$(ITEM:.c=.o)

$(NAME):
	@echo "Compiling for $(NAME)"
	@make -C $(FT)/
	@make -C $(GNL)/
	@echo "Compiling $(NAME)"
ifeq ("$t", "true")
	@tar -xf varz/minilibx_macos_20151105.tgz
	@make -C $(MLX)
endif
	@$(CC) $(SRC) $(CFLAGS) $(LIBS) $(GNL)/get_next_line.o -o $(NAME) -Llibft/ -Ilibft -lft -I $(INC_D)
	@echo "$(NAME) is ready!"

all: $(NAME)

clean:
	@echo "Cleaning objects for $(NAME)"
	@make -C $(FT)/ clean
	@make -C $(GNL)/ clean
	@echo "Cleaning objects of $(NAME)"
	@rm -f $(OBJ)

fclean: clean
	@echo "Cleaning for $(NAME)"
	@make -C $(FT)/ fclean
	@make -C $(GNL)/ fclean
	@echo "Cleaning $(NAME)"
	@rm -f $(LIB)
	@rm -f $(NAME)
ifeq ("$t", "true")
	@rm -rf $(MLX)
endif

re: fclean all
