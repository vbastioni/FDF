/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 09:44:15 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/26 12:42:39 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define BOARD_MAX_WIDTH 800
# define W_H BOARD_MAX_WIDTH    // DEPRECATED, TO BE REMOVED!
# define BOARD_NAME ("FdF")
# define W_N BOARD_NAME         // DEPRECATED, TO BE REMOVED!


# ifndef PI
# define PI 3.14159265358979323846
# endif

# ifdef DEBUG
# define DEBUG_VALUE 1
# else
# define DEBUG_VALUE 0
# endif

#endif