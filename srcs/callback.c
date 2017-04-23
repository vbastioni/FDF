#include <stdlib.h>

#include "callback.h"
#include "data.h"
#include "mlx.h"

int	exit_func(int keycode, void *param)
{
    t_data  *data;

    data = (t_data *)param;
    if (keycode == 53)
    {
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
    }
    return (0);
}
