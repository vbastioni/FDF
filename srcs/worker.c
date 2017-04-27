#include <fcntl.h>
#include <unistd.h>

#include <mlx.h>

#include "get_next_line.h"
#include "board.h"
#include "data.h"
#include "libft.h"
#include "worker.h"
#include "defs.h"
#include "callback.h"

int		count_elem(const char *str)
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

int 	preparse_data(const char *filename, t_board **board)
{
	int		fd;
	int		gnl;
	char	*line;

	if (!board || (fd = open(filename, O_RDONLY)) < 0 ||
			(gnl = get_next_line(fd, &line)) < 1)
		return (0);
	*board = Board_create();
	(*board)->pdims.y = 1;
	if (((*board)->pdims.x = count_elem(line)) < 0)
		return (0);
	while ((gnl = get_next_line(fd, &line)) > 0)
		(*board)->pdims.y++;
	close(fd);
	debug_board(*board);
	return (1);
}

int		parse_and_display(const char *filename, t_board *board, const t_data *wdata)
{
	if (!open(filename, O_RDONLY))
		return (0);
	(void)board;
	(void)wdata;
	return (0);
}