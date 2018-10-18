/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:31 by gwood             #+#    #+#             */
/*   Updated: 2018/10/18 13:01:11 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "vector.h"

void		kt_swapvec2d(t_vec2d *v0, t_vec2d *v1)
{
	t_vec2d	swp;

	swp = *v0;
	*v0 = *v1;
	*v1 = swp;

	// swp.x = v0->x;
	// v0->x = v1->x;
	// v1->x = swp.x;

	// swp.y = v0->y;
	// v0->y = v1->y;
	// v1->y = swp.y;
}

static void		kt_drawline2d_h(t_data *d, t_vec2d p0, t_vec2d p1, t_drawline2d line)
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
		kt_swapvec2d(&p0, &p1);
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

static void		kt_drawline2d_v(t_data *d, t_vec2d p0, t_vec2d p1, t_drawline2d line)
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
		kt_swapvec2d(&p0, &p1);
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

void			kt_drawline2d(t_data *d, t_vec2d p0, t_vec2d p1, int color)
{
	t_drawline2d	line;

	XSetForeground(d->dpy, d->gc, color);
	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	if (line.dx == 0)
	{
		if (p1.y < p0.y)
			kt_swapvec2d(&p0, &p1);
		while (p0.y <= p1.y)
			XDrawPoint(d->dpy, d->win, d->gc, (int) p1.x, (int) p0.y++);
	}
	line.m = (double) line.dy / line.dx;
	if (line.m >= 0)
		line.step = 1;
	else
		line.step = -1;
	if (line.m <= 1 && line.m >= -1)
		kt_drawline2d_h(d, p0, p1, line);
	else
		kt_drawline2d_v(d, p0, p1, line);
}
