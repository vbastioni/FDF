NAME=fdf
LIB=fdf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
LIBS=-lmlx -framework OpenGL -framework AppKit
MLX=minilibx_macos
GNL=./gnl
FT=./libft
ifeq ("$t", "true")
LIBS +=-L $(MLX) -I $(MLX)
endif
SRC_D=./srcs/
INC_D=./includes/
ITEM:=$(shell ls ${SRC_D}*.c | sed -E 's/.*\/([0-9A-Za-z_]*\.c)/\1/g')
SRC:=$(addprefix $(SRC_D), $(ITEM))
OBJ:=$(ITEM:.c=.o)

$(NAME): $(SRC)
	@make -C $(FT)
	@make -C $(GNL)
ifeq ("$t", "true")
	@tar -xf ../varz/minilibx_macos_20151105.tgz
	@make -C $(MLX)
endif
	$(CC) $(CFLAGS) -c $? $(SRC) -I $(INC_D) -I ${GNL}/ -I ${FT} -I ${MLX}
	$(CC) $(OBJ) ${GNL}/get_next_line.o -o $(NAME) -L ${FT}/ -lft -L ${MLX}/ -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

mrproper: fclean
	rm -rf $(MLX)