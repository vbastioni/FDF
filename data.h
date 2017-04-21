/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:56:23 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/20 14:49:13 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct	s_data
{
	void		*win;
	void		*mlx;
	void		*data;
	void		*this;
}				t_data;

t_data			*create_data(void *win, void *mlx, void *data);
void			destroy_data(t_data *data);

#endif
