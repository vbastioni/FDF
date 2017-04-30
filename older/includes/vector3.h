/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:54:39 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 13:57:17 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

#include "defs.h"

typedef struct	s_int_vector
{
	int			x;
	int			y;
	int			z;
}				t_int_vector

typedef struct	s_vector
{
	UCHAR		x;
	UCHAR		y;
	UCHAR		z;
}				t_vector

#endif
