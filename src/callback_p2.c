/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_part_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:30:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 15:50:23 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						cb_expose(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->rdr != NULL)
		env->rdr(env);
	return (0);
}

void					change_color(t_env *env)
{
	env->color_id++;
	if (env->color_id == env->color_set_cnt)
		env->color_id = 0;
	env->rdr(env);
}

int						cb_key(int kc, void *param)
{
	t_env				*env;

	env = (t_env *)param;
	if (kc == KC_EXIT)
		close_window(env);
	if (kc == KC_R)
		reset_view(env);
	return (0);
}

int						reset_view(void *param)
{
	t_env				*env;

	env = (t_env *)param;
	env->iso_angles.a = DEF_ANG_X;
	env->iso_angles.b = DEF_ANG_Y;
	env->iso_scale = DEF_ZOOM;
	env->rdr(env);
	return (0);
}
