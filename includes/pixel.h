/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:35:14 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:35:26 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

#include "vertice.h"

typedef struct	    s_pixel
{
    t_vert	    	*vert;
    struct s_pixel   *prev;
    struct s_pixel   *next;
}		    		t_pixel;

int	lstadd(t_pixel **lst, t_vert *vert);

#endif
