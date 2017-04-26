/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:50:22 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 12:21:36 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

#include "board.h"
#include "data.h"

typedef enum	s_display_mode
{
				PARALLEL,
				ISOMETRIC
}				t_display_mode;

int		render_display(t_board *board, t_data *data, t_display_mode mode);

#endif
