/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:06:44 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:18:27 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_DATA_H
# define BOARD_DATA_H

#include "pixel.h"
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

#endif
