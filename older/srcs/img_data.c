/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:33:17 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:33:20 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "img_data.h"

t_img_data	*ImgData_create()
{
	t_img_data	*ret;

	if (!(ret = (t_img_data *)malloc(sizeof(t_img_data))))
		return (NULL);
	ret->bpx = 0;
	ret->sl = 0;
	ret->endian = 0;
	ret->beg = NULL;
	return (ret);
}
