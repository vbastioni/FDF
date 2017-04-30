/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:27:48 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 17:05:39 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fpoint.h"

t_point				fp_to_point(t_fpoint point)
{
	t_point			ret;

	ret.x = (int)ceil(point.x + 0.5);
	ret.y = (int)ceil(point.y + 0.5);
	return (ret);
}

t_fpoint			fp_add(t_fpoint a, t_fpoint b)
{
	t_fpoint		ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_fpoint			fp_mult(t_fpoint a, int n)
{
	t_fpoint		ret;

	ret.x = a.x * (float)n;
	ret.y = a.y * (float)n;
	return (ret);
}

t_fpoint			fp_to_iso(t_fpoint p)
{
	const double	a = cos(PI / 6.0);
	const double	o = 0.25;
	t_fpoint		ret;

	ret.x = p.x * a - p.y * a;
	ret.y = p.x * o + p.y * o;
	return (ret);
}

t_fpoint			fp_new(float x, float y)
{
	t_fpoint		ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
