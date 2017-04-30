/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:13:50 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 10:15:20 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "board.h"

#include "defs.h"

t_board	    *Board_create()
{
    t_board *ret;

    if (!(ret = (t_board *)malloc(sizeof(t_board))))
	return (NULL);
    ret->pixel = NULL;
	ret->pdims = dims_zero();
	ret->bdims = dims_zero();
	ret->delta = dims_zero();
	ret->inter = dims_zero();
    return (ret);
}

void	debug_board(t_board *board)
{
	ft_putstr("Board data:\n\twidth: ");
	ft_putnbr(board->pdims.x);
	ft_putstr(".\n\theight: ");
	ft_putnbr(board->pdims.y);
	ft_putstr(".\n\tz min: ");
	ft_putnbr(board->delta.x);
	ft_putstr(".\n\tz max: ");
	ft_putnbr(board->delta.y);
	ft_putstr(".\n");
}

void	board_set(t_board *board)
{
    board->inter.x = (BOARD_MAX_WIDTH - board->pdims.x) / (board->pdims.x - 1);
	board->inter.y = (BOARD_MAX_WIDTH - board->pdims.y) / (board->pdims.y - 1);
	board->padding.x = (BOARD_MAX_WIDTH - (board->pdims.x + board->inter.x * (board->pdims.x - 1))) / 2;
	board->padding.y = (BOARD_MAX_WIDTH - (board->pdims.y + board->inter.y * (board->pdims.y - 1))) / 2;
}

void	board_set_dims(t_board *board)
{
	board->inter.x = (BOARD_MAX_WIDTH - board->pdims.x) / (board->pdims.x - 1);
	board->inter.y = (BOARD_MAX_WIDTH - board->pdims.y) / (board->pdims.y - 1);
	board->padding.x = (BOARD_MAX_WIDTH - board->inter.x * (board->pdims.x - 1)) / 2;
	board->padding.y = (BOARD_MAX_WIDTH - board->inter.y * (board->pdims.y - 1 )) /2;
}
