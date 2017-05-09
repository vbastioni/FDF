#include "fdf.h"

int						cb_expose(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->rdr != NULL)
		env->rdr(env);
	return(0);
}

int						cb_key(int keycode, void *param)
{
	if (keycode)
		(void)param;
	return (0);
}