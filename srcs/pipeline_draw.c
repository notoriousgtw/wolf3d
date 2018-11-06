/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:39:53 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 14:20:20 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipeline.h"
#include <stdio.h>

static void	kt_pipeline_draw_tri_scanline(t_pipeline *p, t_drawtri *dt, int y)
{
	int		x;
	int		x_end;
	double	dx;
	double	z;
	t_vert	tmp;

	x = (int) ceil(dt->it_edge0.pos.x - 0.5);
	x_end = (int) ceil(dt->it_edge1.pos.x - 0.5);
	kt_vert_dup(&dt->it_edge0, &dt->i_line);
	dx = dt->it_edge1.pos.x - dt->it_edge0.pos.x;
	kt_vert_sub(&dt->it_edge1, &dt->i_line, &tmp);
	kt_vert_div(&tmp, dx, &dt->di_line);
	kt_vert_mult(&dt->di_line, ((double) x + 0.5 - dt->it_edge0.pos.x), &tmp);
	kt_vert_add(&tmp, &dt->i_line, &dt->i_line);
	while (x < x_end)
	{
		z = 1.0 / dt->i_line.pos.z;
		kt_vert_dup(&dt->i_line, &tmp);
		kt_vert_mult(&tmp, z, &tmp);
		XSetForeground(p->x->dpy, p->x->gc,
							p->effect->ps.fnc(&(p->effect->ps), &tmp));
		XDrawPoint(p->x->dpy, p->x->win, p->x->gc, x, y);
		kt_vert_add(&dt->i_line, &dt->di_line, &dt->i_line);
		x++;
	}
}

static void	kt_pipeline_draw_flat_tri(t_pipeline *p, t_drawtri *dt)
{
	int		y;
	int		y_end;
	t_vert	tmp;

	kt_vert_dup(&dt->it0, &dt->it_edge0);
	kt_vert_dup(&dt->it0, &tmp);
	y = (int) ceil(dt->it0.pos.y - 0.5);
	y_end = (int) ceil(dt->it2.pos.y - 0.5);
	kt_vert_mult(&dt->dit0, ((double) y + 0.5 - dt->it0.pos.y), &tmp);
	kt_vert_add(&dt->it_edge0, &tmp, &dt->it_edge0);
	kt_vert_mult(&dt->dit1, ((double) y + 0.5 - dt->it0.pos.y), &tmp);
	kt_vert_add(&dt->it_edge1, &tmp, &dt->it_edge1);
	while (y < y_end)
	{
		kt_pipeline_draw_tri_scanline(p, dt, y);
		XFlush(p->x->dpy);
		kt_vert_add(&dt->it_edge0, &dt->dit0, &dt->it_edge0);
		kt_vert_add(&dt->it_edge1, &dt->dit1, &dt->it_edge1);
		y++;
	}
}

static void	kt_pipeline_draw_flat_tri_top(t_pipeline *p, const t_vert *it0,
											 const t_vert *it1, const t_vert *it2)
{
	double		dy;
	t_drawtri	dt;

	kt_vert_dup(it0, &dt.it0);
	kt_vert_dup(it1, &dt.it1);
	kt_vert_dup(it2, &dt.it2);
	// kt_drawline3d(p->x, dt.it0.pos, dt.it1.pos, GREEN);
	// kt_drawline3d(p->x, dt.it1.pos, dt.it2.pos, GREEN);
	// kt_drawline3d(p->x, dt.it2.pos, dt.it0.pos, GREEN);
	dy = dt.it2.pos.y - dt.it0.pos.y;
	kt_vert_dup(&dt.it2, &dt.dit0);
	kt_vert_sub(&dt.it2, &dt.it0, &dt.dit0);
	kt_vert_div(&dt.dit0, dy, &dt.dit0);
	kt_vert_dup(&dt.it2, &dt.dit1);
	kt_vert_sub(&dt.it2, &dt.it1, &dt.dit1);
	kt_vert_div(&dt.dit1, dy, &dt.dit1);
	kt_vert_dup(&dt.it1, &dt.it_edge1);
	kt_pipeline_draw_flat_tri(p, &dt);
}

static void	kt_pipeline_draw_flat_tri_bottom(t_pipeline *p, const t_vert *it0,
											 const t_vert *it1, const t_vert *it2)
{
	double		dy;
	t_drawtri	dt;

	kt_vert_dup(it0, &dt.it0);
	kt_vert_dup(it1, &dt.it1);
	kt_vert_dup(it2, &dt.it2);
	// kt_drawline3d(p->x, dt.it0.pos, dt.it1.pos, RED);
	// kt_drawline3d(p->x, dt.it1.pos, dt.it2.pos, GREEN);
	// kt_drawline3d(p->x, dt.it2.pos, dt.it0.pos, BLUE);
	dy = dt.it2.pos.y - dt.it0.pos.y;
	kt_vert_dup(&dt.it1, &dt.dit0);
	kt_vert_sub(&dt.it1, &dt.it0, &dt.dit0);
	kt_vert_div(&dt.dit0, dy, &dt.dit0);
	kt_vert_dup(&dt.it2, &dt.dit1);
	kt_vert_sub(&dt.it2, &dt.it0, &dt.dit1);
	kt_vert_div(&dt.dit1, dy, &dt.dit1);
	kt_vert_dup(&dt.it0, &dt.it_edge1);
	kt_pipeline_draw_flat_tri(p, &dt);
}

void			kt_pipeline_draw_tri(t_pipeline *p, t_tri *tri)
{
	double		alpha_split;
	t_vert		vi;

	if (tri->v1.pos.y < tri->v0.pos.y)
		kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
	if (tri->v2.pos.y < tri->v1.pos.y)
		kt_vec3d_swap(&tri->v1.pos, &tri->v2.pos);
	if (tri->v1.pos.y < tri->v0.pos.y)
		kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
	if (tri->v0.pos.y == tri->v1.pos.y)
	{
		if (tri->v1.pos.x < tri->v0.pos.x)
			kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
		kt_pipeline_draw_flat_tri_top(p, &tri->v0, &tri->v1, &tri->v2);
	}
	else if (tri->v1.pos.y == tri->v2.pos.y)
	{
		if (tri->v2.pos.x < tri->v1.pos.x)
			kt_vec3d_swap(&tri->v1.pos, &tri->v2.pos);
		kt_pipeline_draw_flat_tri_bottom(p, &tri->v0, &tri->v1, &tri->v2);
	}
	else
	{
		alpha_split = (tri->v1.pos.y - tri->v0.pos.y) / (tri->v2.pos.y - tri->v0.pos.y);
		kt_vert_dup(&tri->v0, &vi);
		kt_vert_sub(&tri->v2, &tri->v0, &vi);
		kt_vert_mult(&vi, alpha_split, &vi);
		kt_vert_add(&tri->v0, &vi, &vi);
		if (tri->v1.pos.x < vi.pos.x)
		{
			kt_pipeline_draw_flat_tri_bottom(p, &tri->v0, &tri->v1, &vi);
			kt_pipeline_draw_flat_tri_top(p, &tri->v1, &vi, &tri->v2);
		}
		else
		{
			kt_pipeline_draw_flat_tri_bottom(p, &tri->v0, &vi, &tri->v1);
			kt_pipeline_draw_flat_tri_top(p, &vi, &tri->v1, &tri->v2);
		}
	}
}
