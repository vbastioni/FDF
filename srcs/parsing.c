/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:13:23 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 17:12:06 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "utils.h"
#include "parsing.h"
#include "board.h"
#include "dims.h"

static int  validate(char *line, t_dims dims, t_board *board)
{
	t_vert  *v;

	if (!board)
		return (-1);
	if (!(v = create_vert(dims.x, dims.y, line)))
		return (-err("Mem error in create vertice.")); // here too.
	if (!(lstadd(&board->pixel, v)))
		return (-err("Mem error in lstadd")); // do cleaner for pixel
	if (v->z > board->delta.y)
		board->delta.y = v->z;
	else if (v->z < board->delta.x)
		board->delta.x = v->z;
	free(line);
	return (0);
}

static int  parse_line(char *line, t_board *board)
{
	char	**splitted;
	int		i;
	t_dims	dims;

	splitted = ft_strsplit(line, ' ');
	i = -1;
	while (*(splitted + ++i))
	{
		Dims_set(&dims, i, board->pdims.y);
		validate(*(splitted + i), dims, board);
	}
	if (board->pdims.x == 0)
		board->pdims.x = i;
	return (board->pdims.x == i);
}

t_board	    *read_file(char *filename)
{
	int		fd;
	int		gnl_ret;
	char	*line;
	t_board	*board;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ptr_err("this file does not exist"));
	board = Board_create();
	while ((gnl_ret = get_next_line(fd, &line)) > 0)
	{
		if (!(parse_line(line, board)))
			return (ptr_err("Error in a line."));
		board->pdims.y++;
	}
	debug_board(board);
	if (gnl_ret == -1)
		return (ptr_err("Error in file reading..."));
	return (board);
}

void	    debug_vert(const t_vert *vert)
{
	ft_putstr("x: ");
	ft_putnbr(vert->x);
	ft_putstr(", y: ");
	ft_putnbr(vert->y);
	ft_putstr(", z: ");
	ft_putnbr(vert->z);
	ft_putstr(", color: ");
	ft_putnbr(vert->color);
	ft_putendl(".");
}
