#include "preparsing.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "libft.h"

#include <stdio.h>

static int	count_elem(const char *str)
{
	char	flags;
	int		cnt;

	if (!str)
		return (-1);
	flags = 0;
	cnt = 0;
	while (*str)
	{
		flags |= (ft_isspace(*str) * 2);
		if (flags == 3)
		{
			flags ^= 1;
			cnt++;
		}
		else if (flags == 0)
			flags |= 1;
		flags &= 1;
		str++;
	}
	cnt += (flags & 1);
	return (cnt);
}

t_vertex	get_vertex(char **line, int x, int y)
{
	t_vertex	vec;

	vec.pos.x = x;
	vec.pos.y = y;
	vec.pos.z = ft_atoi(*line);
	while (ft_isspace(**line))
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (ft_strncmp(*line, ",0x", 3) == 0)
	{
		(*line) += 3;
		vec.color = ft_atoihex(*line);
		while (ft_isalnum(**line))
			(*line)++;
	}
	else
		vec.color = -1;
	return (vec);
}

static int	convert_data(t_board *board, char *line, int y)
{
	int		x;

	if (!(board->vertex[y] = (t_vertex *)malloc(
			sizeof(t_vertex) * board->pdims.x)))
		return (0);
	x = -1;
	while (++x < board->pdims.x)
        board->vertex[y][x] = get_vertex(&line, x, y);
	return (1);
}

int 	    preparse_data(const char *filename, t_board **board)
{
	int		fd;
	int		gnl;
	char	*line;

	if (!board || (fd = open(filename, O_RDONLY)) < 0 ||
			(gnl = get_next_line(fd, &line)) < 1)
		return (0);
	*board = board_create();
	(*board)->pdims.y = 1;
	if (((*board)->pdims.x = count_elem(line)) < 0)
		return (0);
	while ((gnl = get_next_line(fd, &line)) > 0)
		(*board)->pdims.y++;
	if (!board_prepare(*board))
		return (0);
	close(fd);
	return (1);
}

void		**parse_data(const char *filename, t_board *board)
{
	int		fd;
	char	*line;
	int		y;
	int		gnl;

	y = 0;
    if (!(fd = open(filename, O_RDONLY)))
		return (0);
	while ((gnl = get_next_line(fd, &line)) > 0 &&
			convert_data(board, line, y))
		y++;
	close(fd);
	return (0);
}