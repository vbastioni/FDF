/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:13:50 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:18:26 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "board.h"

t_board	    *Board_create()
{
    t_board *ret;

    if (!(ret = (t_board *)malloc(sizeof(t_board))))
	return (NULL);
    ret->pixel = NULL;
	ret->pdims.x = 0;
	ret->pdims.y = 0;
	ret->bdims.x = 0;
	ret->bdims.y = 0;
	ret->delta.x = 0;
	ret->delta.y = 0;
	ret->inter.x = 0;
    return (ret);
}
