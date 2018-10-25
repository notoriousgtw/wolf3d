/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:50 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:21:35 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <math.h>
# include "graphics.h"
# include "keys.h"
# include "color.h"

typedef struct	s_data
{
	int			changed:1;
	t_keys		pressed;
	t_xvars		x;
	t_color		*color;
}				t_data;

void			bb_start(t_data *d);
void			bb_close(t_data *d);
void			bb_restart(t_data *d);
void			bb_init_pressed(t_data *d);
void			kt_create_window(t_data *d);
void			bb_init_colors(t_data *data);

#endif
