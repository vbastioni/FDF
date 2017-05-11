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

static inline void		change_color(t_env *env)
{
	env->color_id++;
	if (env->color_id > 2)
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
	printf("Current angle: %d\n", env->angle);
	env->rdr(env);
}

int						cb_key(int keycode, void *param)
{
	t_env				*env;

	env = (t_env *)param;
	if (keycode == KC_EXIT)
		exit(0);
	 if (keycode == KC_PAR)
		change_to(PAR, env);
	 if (keycode == KC_ISO)
		change_to(ISO, env);
	 if (keycode == KC_CHANGE_COLOR)
		change_color(env);
	if (keycode == KC_TURN_LEFT || keycode == KC_TURN_RIGHT)
		try_turn(env, keycode);
	return (0);
}