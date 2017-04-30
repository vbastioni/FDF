CC=gcc
CFLAGS=-Wall -Werror -Wextra -c
SRC=get_next_line.c
OBJ=$(SRC:.c=.o)
NAME=get_next_line

all:
	@echo "Compiling $(NAME)"
	@$(CC) $(CFLAGS) $(SRC) -I../libft

clean:
	@echo "Cleaning $(NAME)"
	@/bin/rm -f $(OBJ)

fclean: clean
