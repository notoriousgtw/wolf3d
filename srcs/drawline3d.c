/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:31 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 16:47:01 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "vector.h"

static void		kt_drawline3d_h(t_data *d, t_vec3d p0, t_vec3d p1, t_drawline line)
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
		XDrawPoint(d->dpy, d->win, d->gc, (int) p0.x, (int) p0.y);
		offset += delta;
		if (offset >= thresh)
		{
			p0.y += line.step;
			thresh += thresh_inc;
		}
		p0.x++;
	}
}

static void		kt_drawline3d_v(t_data *d, t_vec3d p0, t_vec3d p1, t_drawline line)
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
		XDrawPoint(d->dpy, d->win, d->gc, (int) p0.x, (int) p0.y);
		offset += delta;
		if (offset >= thresh)
		{
			p0.x += line.step;
			thresh += thresh_inc;
		}
		p0.y++;
	}
}

void			kt_vec3d_screenify(t_data *d, t_vec3d *v)
{
	const double	z_inv = 1.0 / v->z;

	v->x = (v->x * z_inv + 1) * ((double) d->width / 2);
	v->y = (-v->y * z_inv + 1) * ((double) d->height / 2);
}

void			kt_drawline3d(t_data *d, t_vec3d p0, t_vec3d p1, int color)
{
	t_drawline	line;

	kt_vec3d_screenify(d, &p0);
	kt_vec3d_screenify(d, &p1);
	if ((int) p0.x < 0 || (int) p0.x > d->width
		|| (int) p0.y < 0 || (int) p0.y > d->height)
		return;
	XSetForeground(d->dpy, d->gc, color);
	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	if (line.dx == 0)
	{
		if (p1.y < p0.y)
			kt_vec3d_swap(&p0, &p1);
		while (p0.y <= p1.y)
			XDrawPoint(d->dpy, d->win, d->gc, (int) p1.x, (int) p0.y++);
	}
	line.m = (double) line.dy / line.dx;
	if (line.m >= 0)
		line.step = 1;
	else
		line.step = -1;
	if (line.m <= 1 && line.m >= -1)
		kt_drawline3d_h(d, p0, p1, line);
	else
		kt_drawline3d_v(d, p0, p1, line);
}
