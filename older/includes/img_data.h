/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:34:46 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/24 14:34:58 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_DATA_H
# define IMG_DATA_H

typedef struct	s_img_data
{
    int			bpx;
    int			sl;
    int			endian;
    char		*beg;
}				t_img_data;

t_img_data	*ImgData_create();

#endif
