/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:00 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 16:14:59 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "utils.h"
#include "vertice.h"
#include "parsing.h"

t_vert	*create_vert(int x, int y, char *data)
{
	t_vert  *v;
	char    **splitted;

	if (!(v = (t_vert *)malloc(sizeof(t_vert))))
		return (ptr_err("Could not create vertice.")); 
	if (!(splitted = ft_strsplit(data, ',')))
		return (ptr_err("Could not split data"));
	v->x = x;
	v->y = y;
	v->z = ft_atoi(splitted[0]);
	v->color = splitted[1] ? ft_atoibase(splitted[1] + 2, "0123456789abcdef") : -1;
	return (v);
}
