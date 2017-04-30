/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:16:03 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 17:05:40 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPOINT_H
# define FPOINT_H

#include <math.h>

# ifdef PI
# undef PI
# endif
# define PI 3.14159265359

typedef struct		s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_fpoint			fp_new(float x, float y);
t_point				fp_to_point(t_fpoint point);
t_fpoint			fp_add(t_fpoint a, t_fpoint b);
t_fpoint			fp_mult(t_fpoint a, int n);
t_fpoint			fp_to_iso(t_fpoint point);

#endif
