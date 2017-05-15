/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 13:28:07 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/15 13:29:23 by vbastion         ###   ########.fr       */
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

static inline void		change_render(t_mode mode, t_env *env)
{
	if (env->render_mode == mode)
		return ;
	env->render_mode = mode;
	if (mode == 0)
		env->rdr = &draw_par;
	else if (mode == 1)
		env->rdr = &draw_iso;
	env->rdr(env);
}

static inline void		change_color(t_env *env)
{
	env->color_id++;
	if (env->color_id == COLOR_SET_CNT)
		env->color_id = 0;
	env->rdr(env);
}

static inline void		change_rotation(t_env *env, int keycode)
{
	if (env->render_mode != ISO)
		return ;
	if (keycode == KC_LEFT)
		env->iso_angles.a += 5.0;
	else if (keycode == KC_RIGHT)
		env->iso_angles.a -= 5.0;
	if (keycode == KC_UP)
		env->iso_angles.b += 5.0;
	else if (keycode == KC_DOWN)
		env->iso_angles.b -= 5.0;
	if (env->iso_angles.a < 0)
		env->iso_angles.a += 360.0;
	else if (env->iso_angles.a > 360.0)
		env->iso_angles.a -= 360.0;
	if (env->iso_angles.b < 0)
		env->iso_angles.b += 360.0;
	else if (env->iso_angles.b > 360.0)
		env->iso_angles.b -= 360.0;
	env->rdr(env);
}

void					change_height(int dir, t_env *env)
{
	if (env->render_mode != ISO)
		return ;
	env->zcoeff -= dir;
	env->rdr(env);
}

int						change_scale(int val, t_env *env)
{
	if (env->render_mode != ISO)
		return (1);
	env->iso_scale += val;
	env->rdr(env);
	return (0);
}

int						change_pos(int kc, t_env *env)
{
	t_dims				dir;

	if (kc == KC_A || kc == KC_D)
		dir.x = (kc == KC_D) ? 1 : -1;
	else
		dir.x = 0;
	if (kc == KC_W || kc == KC_S)
		dir.y = (kc == KC_S) ? 1 : -1;
	else
		dir.y = 0;
	env->iso_delta.x += (dir.x * MOVE_STEP);
	env->iso_delta.y += (dir.y * MOVE_STEP);
	env->rdr(env);
	return (0);
}

int						reset_view(void *param)
{
	t_env				*env;

	env = (t_env *)param;
	env->iso_angles.a = DEF_ANG_X;
	env->iso_angles.b = DEF_ANG_Y;
	env->rdr(env);
	return (0);
}

int						cb_key(int kc, void *param)
{
	t_env				*env;

	env = (t_env *)param;
	if (kc == KC_EXIT)
		exit(0);
	if (kc == KC_PAR)
		change_render(PAR, env);
	if (kc == KC_ISO)
		change_render(ISO, env);
	if (kc == KC_R)
		reset_view(env);
	return (0);
}

int						cb_cont_key(int kc, void *param)
{
	t_env				*env;

	env = (t_env *)param;
	if (kc == KC_CHANGE_COLOR)
		change_color(env);
	if (kc == KC_LEFT || kc == KC_RIGHT || kc == KC_UP || kc == KC_DOWN)
		change_rotation(env, kc);
	if (kc == KC_PG_DOWN || kc == KC_PG_UP || kc == KC_Q || kc == KC_E)
		change_height((kc == KC_PG_DOWN || kc == KC_E) ? -1 : 1, env);
	if (kc == KC_O || kc == KC_P)
		change_scale(kc == KC_P ? 1 : -1, env);
	if (kc == KC_W || kc == KC_S || kc == KC_A || kc == KC_D)
		change_pos(kc, env);
	return (0);
}
