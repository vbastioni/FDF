CC=gcc
CFLAGS=-Wall -Werror -Wextra -c
SRC=get_next_line.c
OBJ=$(SRC:.c=.o)

all:
	$(CC) $(CFLAGS) $(SRC) -I../libft

clean:
	/bin/rm -f $(OBJ)

fclean: clean
