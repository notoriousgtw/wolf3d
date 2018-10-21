/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:31 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 00:00:06 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		kt_drawline3d_h(t_xvars *x, t_vec3d p0, t_vec3d p1, t_drawline line)
{
	int	offset;
	int	delta;
	int	thresh;
	int	thresh_inc;

	offset = 0;
	delta = abs(line.dy) * 2;
	thresh = abs(line.dx);
	thresh_inc = abs(line.dx) * 2;
	if (p1.x < p0.x)
		kt_vec3d_swap(&p0, &p1);
	while ((int) p0.x <= (int) p1.x)
	{
		XDrawPoint(x->dpy, x->win, x->gc, (int) p0.x, (int) p0.y);
		offset += delta;
		if (offset >= thresh)
		{
			p0.y += line.step;
			thresh += thresh_inc;
		}
		p0.x++;
	}
}

static void		kt_drawline3d_v(t_xvars *x, t_vec3d p0, t_vec3d p1, t_drawline line)
{
	int	offset;
	int	delta;
	int	thresh;
	int	thresh_inc;

	offset = 0;
	delta = abs(line.dx) * 2;
	thresh = abs(line.dy);
	thresh_inc = abs(line.dy) * 2;
	if (p1.y < p0.y)
		kt_vec3d_swap(&p0, &p1);
	while ((int) p0.y <= (int) p1.y)
	{
		XDrawPoint(x->dpy, x->win, x->gc, (int) p0.x, (int) p0.y);
		offset += delta;
		if (offset >= thresh)
		{
			p0.x += line.step;
			thresh += thresh_inc;
		}
		p0.y++;
	}
}

void			kt_drawline3d(t_xvars *x, t_vec3d p0, t_vec3d p1)
{
	t_drawline	line;

	kt_vec3d_screenify(x, &p0);
	kt_vec3d_screenify(x, &p1);
	if ((int) p0.x < 0 || (int) p0.x > x->width
		|| (int) p0.y < 0 || (int) p0.y > x->height)
		return;
	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	if (line.dx == 0)
	{
		if (p1.y < p0.y)
			kt_vec3d_swap(&p0, &p1);
		while (p0.y <= p1.y)
			XDrawPoint(x->dpy, x->win, x->gc, (int) p1.x, (int) p0.y++);
	}
	line.m = (double) line.dy / line.dx;
	if (line.m >= 0)
		line.step = 1;
	else
		line.step = -1;
	if (line.m <= 1 && line.m >= -1)
		kt_drawline3d_h(x, p0, p1, line);
	else
		kt_drawline3d_v(x, p0, p1, line);
}
