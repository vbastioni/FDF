/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:06:44 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 15:09:21 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_DATA_H
# define BOARD_DATA_H

#include "pixel.h"
#include "data.h"
#include "dims.h"

typedef struct	s_board
{
    t_pixel		*pixel;
	t_dims		pdims;
	t_dims		bdims;
	t_dims		delta;
	t_dims		inter;
	t_dims		padding;
}				t_board;

t_board			*Board_create();

void			debug_board(t_board *board);

void			board_set(t_board *board);
void			board_set_dims(t_board *board);

#endif
