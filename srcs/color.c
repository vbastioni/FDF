/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:47 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:32:50 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	color_lerp(int color_from, int color_to, float pct)
{
	if (color_from == color_to)
		return (color_from);
	return (color_from + ((color_to - color_from) * pct));
}
