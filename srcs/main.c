/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/21 16:08:05 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "data.h"
#include "parsing.h"
#include "callback.h"
#include "displays.h"
#include "board.h"
#include "utils.h"

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
    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "mlx 42");
    wdata = create_data(win, mlx);
    display(board, wdata);
    mlx_key_hook(win, exit_func, create_data(win, mlx));
    mlx_loop(mlx);
    return (0);
}
