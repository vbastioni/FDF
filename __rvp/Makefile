NAME=fdf
LIB=fdf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
GNL=./gnl
FT=./libft
LIBS=-lmlx -framework OpenGL -framework AppKit
INCS=-I ${INC_D} -I ${GNL} -I ${FT}
MLX=minilibx_macos
ifeq ("$t", "true")
LIBS +=-L $(MLX)
INCS +=-I $(MLX)
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
	$(CC) $(CFLAGS) -c $? $(SRC) ${INCS}
	$(CC) $(OBJ) ${GNL}/get_next_line.o -o $(NAME) -L ${FT}/ -lft  $(LIBS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

mrproper: fclean
	@printf "\e[31mCleaning Minilibx.\e[30;0m\n"
	@rm -rf $(MLX)
	@printf "\e[31mCleaning GNL.\e[30;0m\n"
	@make -C ${GNL} fclean
