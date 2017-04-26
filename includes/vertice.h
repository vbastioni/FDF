/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:35:49 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 13:58:51 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTICE_H
# define VERTICE_H

typedef struct	s_vert
{
    int		    x;
    int		    y;
    int		    z;
    int		    color;
}		    	t_vert;

t_vert			*create_vert(int x, int y, char *data);

#endif
