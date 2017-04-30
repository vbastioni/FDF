/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dims.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:32 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 09:50:24 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIMS_H
# define DIMS_H

typedef struct	s_dims
{
    int		x;
    int		y;
}		t_dims;

void	Dims_set(t_dims *dims, int x, int y);
t_dims	dims_zero();

#endif
