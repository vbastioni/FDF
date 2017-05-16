/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:39:49 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/16 15:39:50 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					set_env_iso_delta(t_env *e)
{
	t_fvector			lims[2];

	lims[0] = get_iso_pos(&e->vertex[0][0].pos, e);
	lims[1] = get_iso_pos(&e->vertex[e->pdims.y - 1][e->pdims.x - 1].pos, e);
	e->iso_d.x = (lims[1].a - lims[0].a) / 2;
	e->iso_d.y = (lims[1].b - lims[0].b) / 2;
}
