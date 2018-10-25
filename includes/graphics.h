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
# include "matrix.h"
# include "vertex.h"
# include "vertlist.h"
# include "linelist.h"
# include "trilist.h"
# include "mesh.h"
// # include "shapes.h"
# include <math.h>

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

typedef struct	s_drawtri
{
	double	m0;
	double	m1;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
	double	px0;
	double	px1;
}				t_drawtri;

typedef struct	s_drawtri_tex
{
	t_xvars	*x;
	double	m0;
	double	m1;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
	double	px0;
	double	px1;
}				t_drawtri_tex;

void		kt_drawline2d(t_xvars *x, t_vec2d p0, t_vec2d p1);
void		kt_drawline3d(t_xvars *x, t_vec3d p0, t_vec3d p1);
void		kt_drawtri2d(t_xvars *d, t_vec2d p0, t_vec2d p1, t_vec2d p2);
void		kt_drawtri3d(t_xvars *d, t_vec3d p0, t_vec3d p1, t_vec3d p2);

// void			kt_vec3d_screenify(t_xvars *x, t_vec3d *v);

#endif
