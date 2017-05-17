/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:29:44 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 17:35:16 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			col_get(t_vertex v, const t_env *env)
{
	float	pct;

	if (env->color_id == 3 && v.color.color != -1)
		return (v.color.color);
	if (env->alts.x == env->alts.y)
	{
		return (env->color_sets[env->color_id].x != 0
				? env->color_sets[env->color_id].x
				: env->color_sets[env->color_id].y);
	}
	pct = (float)(v.pos.z - env->alts.x) / (float)(env->alts.y - env->alts.x);
	return (color_lerp(env->color_sets[env->color_id].x,
						env->color_sets[env->color_id].y, pct));
}

int			color_lerp(int color_from, int color_to, double pct)
{
	t_color	f;
	t_color	t;
	t_color	r;

	if (color_from == color_to)
		return (color_from);
	f.color = color_from;
	t.color = color_to;
	r.color = 0x0;
	r.c[0] = f.c[0] + (t.c[0] - f.c[0]) * pct;
	r.c[1] = f.c[1] + (t.c[1] - f.c[1]) * pct;
	r.c[2] = f.c[2] + (t.c[2] - f.c[2]) * pct;
	return (r.color);
}
