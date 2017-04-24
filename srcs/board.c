/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:13:50 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 15:05:19 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "board.h"

t_board	    *Board_create()
{
    t_board *ret;

    if (!(ret = (t_board *)malloc(sizeof(t_board))))
	return (NULL);
    ret->pixel = NULL;
	ret->pdims.x = 0;
	ret->pdims.y = 0;
	ret->bdims.x = 0;
	ret->bdims.y = 0;
	ret->delta.x = 0;
	ret->delta.y = 0;
	ret->inter.x = 0;
    return (ret);
}

void	debug_board(t_board *board)
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

void	board_set_dims(t_board *board)
{
	board->inter.x = (400 - board->pdims.x) / (board->pdims.x - 1);
	board->inter.y = (400 - board->pdims.y) / (board->pdims.y - 1);
	board->padding.x = (400 - board->inter.x * (board->pdims.x - 1)) / 2;
	board->padding.y = (400 - board->inter.y * (board->pdims.y - 1 )) /2;
}
