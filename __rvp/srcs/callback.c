#include "fdf.h"

int						cb_expose(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->rdr != NULL)
		env->rdr(env);
	return(0);
}

static inline void		change_to(t_mode mode, t_env *env)
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

void					zoom(t_env *env, int keycode)
{
	//
	(void)env; (void)keycode;
}

void					scale(t_env *env, int keycode)
{
	//
	(void)env; (void)keycode;
}

static inline void		change_color(t_env *env)
{
	env->color_id++;
	if (env->color_id == COLOR_SET_CNT)
		env->color_id = 0;
	env->rdr(env);
}

static inline void		try_turn(t_env *env, int keycode)
{
	if (env->render_mode != ISO)
		return ;
	env->angle += ANGLE_STEP * (keycode == KC_TURN_LEFT ? -1 : 1);
	if (env->angle < 0)
		env->angle += 360;
	else if (env->angle > 360)
		env->angle -= 360;
	env->rdr(env);
}

void					scale_up(int dir, t_env *env)
{
	if (env->render_mode != ISO)
		return ;
	env->zcoeff += dir;
	env->rdr(env);
}

int						up_scale(int val, t_env *env)
{
	if (env->render_mode != ISO)
		return (1);
	env->iso_scale += val;
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
		change_to(PAR, env);
	 if (kc == KC_ISO)
		change_to(ISO, env);
	 if (kc == KC_CHANGE_COLOR)
		change_color(env);
	if (kc == KC_TURN_LEFT || kc == KC_TURN_RIGHT)
		try_turn(env, kc);
	if (kc == KC_PG_DOWN || kc == KC_PG_UP || kc == KC_Q || kc == KC_E)
		scale_up((kc == KC_PG_UP || kc == KC_E) ? -1 : 1, env);
	if (kc == KC_O || kc == KC_P)
		up_scale(kc == KC_P ? 1 : -1, env);
	// handle movement
	// Keys added. Need handling.
	// Like in fractol.
	return (0);
}