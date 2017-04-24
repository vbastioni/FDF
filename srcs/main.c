/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:12:51 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "data.h"
#include "parsing.h"
#include "callback.h"
#include "displays.h"
#include "board.h"
#include "utils.h"
#include "libft.h"

static void	debug_board(t_board *board)
{
	ft_putstr("Board data:\n\theight: ");
	ft_putnbr(board->pdims.x);
	ft_putstr(".\n\twidth: ");
	ft_putnbr(board->pdims.y);
	ft_putstr(".\n\tz min: ");
	ft_putnbr(board->delta.x);
	ft_putstr(".\n\tz max: ");
	ft_putnbr(board->delta.y);
	ft_putstr(".\n");
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_board	*board;
	t_data	*wdata;

	if (ac < 2)
		return (1);
	if (!(board = read_file(av[1])))
		return (1);
	debug_board(board);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	wdata = create_data(win, mlx);
	display(board, wdata);
	mlx_key_hook(win, exit_func, create_data(win, mlx));
	mlx_loop(mlx);
	return (0);
}
