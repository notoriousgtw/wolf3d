/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:50 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 18:50:40 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <math.h>
# include "graphics.h"
# include "keys.h"

typedef struct	s_data
{
	int			changed:1;
	t_keys		pressed;
	t_xvars		x;
}				t_data;

void			draw_cube(t_xvars *x);
void			restart(t_data *d);
void			init_pressed(t_data *d);
void			redraw(t_data *d);

#endif
