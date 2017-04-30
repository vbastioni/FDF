/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:33:53 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 09:46:31 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "utils.h"

#include "defs.h"

int	err(const char *str)
{
	if (DEBUG_VALUE)
	{
		ft_putstr("[ERR]: ");
		ft_putendl(str);
	}
	return (1);
}

void	*ptr_err(const char *str)
{
	err(str);
	return (NULL);
}
