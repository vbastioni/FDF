NAME=gnl
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRC=get_next_line.c
OBJ=$(SRC:.c=.o)
NAME=get_next_line


$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $? $(SRC) -I../libft

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
