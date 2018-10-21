/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtri3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:56:16 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 11:12:09 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	kt_drawtri3d_up(t_xvars *d, t_vec3d p0, t_vec3d p1, t_vec3d p2)
{
	int			x;
	int			y;
	t_drawtri	t;

	t.m0 = (p1.x - p0.x) / (p1.y - p0.y);
	t.m1 = (p2.x - p0.x) / (p2.y - p0.y);
	t.y_start = (int) ceil(p0.y - 0.5);
	t.y_end = (int) ceil(p2.y - 0.5);
	y = t.y_start - 1;
	while (++y < t.y_end)
	{
		t.px0 = t.m0 * ((double) y + 0.5 - p0.y) + p0.x;
		t.px1 = t.m1 * ((double) y + 0.5 - p0.y) + p0.x;
		t.x_start = (int) ceil(t.px0 - 0.5);
		t.x_end = (int) ceil(t.px1 - 0.5);
		x = t.x_start - 1;
		while (++x < t.x_end)
			XDrawPoint(d->dpy, d->win, d->gc, x, y);
	}
}

static void	kt_drawtri3d_down(t_xvars *d, t_vec3d p0, t_vec3d p1, t_vec3d p2)
{
	int			x;
	int			y;
	t_drawtri	t;

	t.m0 = (p2.x - p0.x) / (p2.y - p0.y);
	t.m1 = (p2.x - p1.x) / (p2.y - p1.y);
	t.y_start = (int) ceil(p0.y - 0.5);
	t.y_end = (int) ceil(p2.y - 0.5);
	y = t.y_start - 1;
	while (++y < t.y_end)
	{
		t.px0 = t.m0 * ((double) y + 0.5 - p0.y) + p0.x;
		t.px1 = t.m1 * ((double) y + 0.5 - p1.y) + p1.x;
		t.x_start = (int) ceil(t.px0 - 0.5);
		t.x_end = (int) ceil(t.px1 - 0.5);
		x = t.x_start - 1;
		while (++x < t.x_end)
			XDrawPoint(d->dpy, d->win, d->gc, x, y);
	}
}

void	kt_drawtri3d(t_xvars *d, t_vec3d p0, t_vec3d p1, t_vec3d p2)
{
	double	alpha_split;
	t_vec3d	vi;

	if (p1.y < p0.y)
		kt_vec3d_swap(&p0, &p1);
	if (p2.y < p1.y)
		kt_vec3d_swap(&p1, &p2);
	if (p1.y < p0.y)
		kt_vec3d_swap(&p0, &p1);
	if (p0.y == p1.y)
	{
		if (p1.x < p0.x)
			kt_vec3d_swap(&p0, &p1);
		kt_drawtri3d_down(d, p0, p1, p2);
	}
	else if (p1.y == p2.y)
	{
		if (p2.x < p1.x)
			kt_vec3d_swap(&p1, &p2);
		kt_drawtri3d_up(d, p0, p1, p2);
	}
	else
	{
		alpha_split = (p1.y - p0.y) / (p2.y - p0.y);
		vi.x = p0.x + (p2.x - p0.x) * alpha_split;
		vi.y = p0.x + (p2.y - p0.y) * alpha_split;
		if (p1.x < vi.x)
		{
			kt_drawtri3d_up(d, p0, p1, vi);
			kt_drawtri3d_down(d, p1, vi, p2);
		}
		else
		{
			kt_drawtri3d_up(d, p0, vi, p1);
			kt_drawtri3d_down(d, vi, p1, p2);
		}
	}
}
