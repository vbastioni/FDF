/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/27 10:34:59 by vbastion         ###   ########.fr       */
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
#include "worker.h"

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_board	*board;
	t_data	*wdata;

	if (ac < 2)
		return (1);
	if (!preparse_data(av[1], &board))
		return (1);
	board_set(board);
	mlx = mlx_init();
	win = mlx_new_window(mlx, BOARD_MAX_WIDTH, BOARD_MAX_WIDTH, BOARD_NAME);
	wdata = create_data(win, mlx);
	parse_and_display(av[1], board, wdata);
	mlx_key_hook(win, exit_func, create_data(win, mlx));
	mlx_loop(mlx);
	return (0);
}
