/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 11:01:55 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 11:08:10 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		img_set(t_img *img, const t_env *env)
{
	if ((img->img = mlx_new_image(env->mlx, WIN_X, WIN_Y)) == NULL)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bpx, &img->sl, &img->endian);
	img->bpx /= 8;
	return (1);
}
