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
# include "libft.h"
# include "vector.h"
# include "vertlist.h"
# include "linelist.h"

typedef struct	s_xvars
{
	Display *dpy;
	int		scr;
	int		black_color;
	int		white_color;
	int		width;
	int		height;
	Window	win;
	GC		gc;
}				t_xvars;
typedef struct	s_drawline
{
	double	m;
	int		step;
	int		dx;
	int		dy;
}				t_drawline;

void		kt_drawline2d(t_xvars *x, t_vec2d p0, t_vec2d p1, int color);
void		kt_drawline3d(t_xvars *x, t_vec3d p0, t_vec3d p1, int color);

// void			kt_vec3d_screenify(t_xvars *x, t_vec3d *v);

#endif
