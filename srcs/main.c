/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/20 16:50:40 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>

#include "data.h"
#include "libft.h"

int		exit_func(int keycode,void *param)
{
	int		par;
	t_data	*data;

	data = (t_data *)param;
	par = *((int *)(data->data));
	if (par == keycode)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		exit(0);
	}
	return (0);
}

void	read_files(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_putenld(line);
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		keycode;
	t_data	*data;

	if (ac < 2)
		return (1);
	read_files(av[1]);
	exit(0);
	keycode = 53;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	data = create_data(win, mlx, &keycode);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, exit_func, data);
	mlx_loop(mlx);

	return (0);
}
