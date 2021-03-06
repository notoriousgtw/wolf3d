/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_2d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:43 by gwood             #+#    #+#             */
/*   Updated: 2018/10/18 12:50:35 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <X11/Xlib.h>
# include "color.h"
# include <math.h>

typedef struct	s_xvars
{
	Display 	*dpy;
	int			scr;
	int			color;
	int			width;
	int			height;
	Window		win;
	GC			gc;
}				t_xvars;

# include "vector.h"

typedef struct	s_drawline
{
	double	m;
	int		step;
	int		dx;
	int		dy;
}				t_drawline;

void			kt_drawline3d(t_xvars *x, t_vec3d p0, t_vec3d p1, int color);

#endif
