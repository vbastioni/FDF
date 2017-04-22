/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:55:36 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/21 16:08:05 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>

#include "data.h"
#include "parsing.h"
#include "get_next_line.h"
#include "libft.h"
#include "pixel.h"
#include "utils.h"

int		read_file(char *filename);
int		exit_func(int keycode, void *param);
int		main(int ac, char **av);

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

int	work(char *line)
{
    char	**splitted;
    t_pixel	*lst;
    int		i;

    i = -1;
    splitted = ft_strsplit(line, ' ');
    while (*(splitted + ++i))
	validate(*(splitted + i), i, &lst);
    return (0);
}

int		read_file(char *filename)
{
    int		fd;
    int		gnl_ret;
    char	*line;

    if ((fd = open(filename, O_RDONLY)) < 0)
	return (err("this file does not exist"));
    while ((gnl_ret = get_next_line(fd, &line)) > 0)
	if (!(work(line)))
	    return (0 * err("Error in a line."));
    if (gnl_ret == -1)
	return (err("Error in file reading..."));
    return (1);
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
    if (!read_file(av[1]))
	return (1);
    keycode = 53;
    (void)av;
    exit(0);
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
