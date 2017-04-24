/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:33:53 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:33:54 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "utils.h"

int	err(const char *str)
{
	ft_putstr("[ERR]: ");
	ft_putendl(str);
	return (0);
}

void	*ptr_err(const char *str)
{
	err(str);
	return (NULL);
}
