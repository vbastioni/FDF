#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"
#include "board.h"
#include "data.h"
#include "libft.h"
#include "worker.h"

int		count_elem(const char *str)
{
	char	flags;
	int		cnt;

    ft_putstr("In count_elem.\n");
	ft_putendl(str);
	if (!str)
		return (-1);
	flags = 0;
	cnt = 0;
	while (*str)
	{
		ft_putendl(str);
		ft_putstr("Current count: ");
		ft_putnbr(cnt);
		ft_putstr("\n");
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
		ft_putendl(str);
		ft_putstr("Current count: ");
		ft_putnbr(cnt);
		ft_putstr("\n");
	ft_putstr("Done counting elems.\n");
	return (cnt);
}

int 	preparse_data(const char *filename, t_board **board)
{
	int		fd;
	int		gnl;
	char	*line;

	ft_putstr("In preparse_data.\n");
	if (!board || (fd = open(filename, O_RDONLY)) < 0 ||
			(gnl = get_next_line(fd, &line)) < 1)
		return (0);
	*board = Board_create();
	(*board)->pdims.y = 1;
	if (((*board)->pdims.x = count_elem(line)) < 0)
		return (0);
	ft_putstr("Done counting elements in first line, count lines.\n");
	while ((gnl = get_next_line(fd, &line)) > 0)
		(*board)->pdims.y++;
	close(fd);
	debug_board(*board);
	return (1);
}