/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 16:13:11 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <stdlib.h>//

#include "data.h"
#include "parsing.h"
#include "callback.h"
#include "displays.h"
#include "board.h"
#include "utils.h"
#include "libft.h"

#include "defs.h"

#include "renderer.h"

#include "get_next_line.h"

#include <fcntl.h>

int	get_initial_data(const char *filename)
{
	int		fd;
	int		gnl;
	char	*line;
	char	**splitted;
	t_dims	bdims;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	if ((gnl = get_next_line(fd, &line)) < 1)
		return (0);
	bdims.x = 0;
	bdims.y = 1;
	splitted = ft_strsplit(line, ' ');
	while (*(splitted + bdims.x))
		bdims.x++;
	while ((gnl = get_next_line(fd, &line)) > 0)
		bdims.y++;
	ft_putstr("Dims: [");
	ft_putnbr(bdims.x);
	ft_putstr(" ,");
	ft_putnbr(bdims.y);
	ft_putstr("].\n");
	return (1);
}
int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_board	*board;
	t_data	*wdata;

	if (ac < 2)
		return (1);
	get_initial_data(av[1]);
	exit(0);
	if (!(board = read_file(av[1])))
		return (1);
	//	exit(0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, W_H, W_H, W_N);
	wdata = create_data(win, mlx);
	if (ac == 3 && ft_strcmp(av[2], "ISOPLEASE") == 0)
		render_display(board, wdata, ISOMETRIC);
	else
		display(board, wdata);
	mlx_key_hook(win, exit_func, create_data(win, mlx));
	mlx_loop(mlx);
	return (0);
}
