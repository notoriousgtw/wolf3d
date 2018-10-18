/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:31 by gwood             #+#    #+#             */
/*   Updated: 2018/10/17 19:54:26 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "vector.h"

static void	get_step(t_vec2d_i p0, t_vec2d_i p1, int *step)
{
	if (p0.x < p1.x)
		step[0] = 1;
	else
		step[0] = -1;
	if (p0.y < p1.y)
		step[1] = 1;
	else
		step[1] = -1;
}

void		kt_drawline2d(t_data *d, t_vec2d p0, t_vec2d p1, int color)
{
	t_vec2d_i	p0_i;
	t_vec2d_i	p1_i;
	int			delta[2];
	int			step[2];
	int			err[2];

	XSetForeground(d->dpy, d->gc, color);
	kt_vec2d_ftoi(p0, &p0_i, 0);
	kt_vec2d_ftoi(p1, &p1_i, 0);
	delta[0] = abs(p1_i.x - p0_i.x);
	delta[1] = abs(p1_i.y - p0_i.y);
	get_step(p0_i, p1_i, step);
	if ( delta[0] > delta[1])
		err[1] = delta[0];
	else
		err[1] = -delta[1];
	while (1)
	{
		XDrawPoint(d->dpy, d->win, d->gc, p0_i.x, p0_i.y);
		if (p0_i.x == p1_i.x && p0_i.y == p1_i.y)
			break;
		err[0] = err[1];
		if (err[0] > -delta[0])
		{
			err[1] -= delta[1];
			p0_i.x += step[0];
		}
		if (err[1] < delta[1])
		{
			err[1] += delta[0];
			p0_i.y += step[1];
		}
	}
}
