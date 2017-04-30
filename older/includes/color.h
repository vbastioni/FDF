/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:22 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 16:50:50 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vertice.h"
# include "board.h"

# define COLOR_MIN 0x0000FF
# define COLOR_MAX 0x000000
//# define COLOR_MAX 0x00FF00
# define COLOR_DEFAULT 0xFFFFFF

typedef unsigned char	UCHAR;

int						color_lerp(int color_from, int color_to, float pct);

int						get_color(const t_vert *vert, const t_board *board);

#endif
