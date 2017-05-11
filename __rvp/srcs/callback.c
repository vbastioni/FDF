#include "fdf.h"

int						cb_expose(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->rdr != NULL)
		env->rdr(env);
	return(0);
}

void					change_color(t_env *env)
{
	printf("Current color set id: %d\n\tColor#0: 0x%x\n\tColor#1: 0x%x\n",
			env->color_id,
			env->color_sets[env->color_id].x,
			env->color_sets[env->color_id].y);
	env->color_id++;
	if (env->color_id > 2)
	{
		printf("Reseting color id.\n");
		env->color_id = 0;
	}
	env->rdr(env);
}

int						cb_key(int keycode, void *param)
{
	t_env				*env;

	env = (t_env *)param;
	if (keycode)
	{
		ft_putnbr(keycode);
		ft_putstr("\n");
		(void)param;
	}
	if (keycode == KC_EXIT)
		exit(0);
	if (keycode == KC_CHANGE_COLOR)
		change_color(env);
	return (0);
}