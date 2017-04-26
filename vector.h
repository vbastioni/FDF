/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:45:51 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 17:06:44 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef enum	e_axis
{
	X,
	Y,
	Z
}				t_axis;

#include <math.h>

t_vector		get_unit_vector(t_axis axis)
{
	t_vector	ret;

	ret.x = cos(PI / 6.0);
	ret.y = 0.25;
	return (ret);
}

t_vector		vector_mult(t_vector v, int n)
{
	v.x *= n;
	v.y *= n;
	return (v);
}

t_dims			vector_to_point(t_vector v)
{
	t_dims		ret;

	ret.x = (int)v.x;
	ret.y = (int)v.y;
	return (ret);
}

#endif
