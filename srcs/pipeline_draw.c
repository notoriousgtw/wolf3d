/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:39:53 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 15:55:53 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipeline.h"

static void	kt_pipeline_draw_tri_scanline(t_pipeline *p, t_drawtri *dt, int y)
{
	int		x;
	int		x_end;
	double	dx;
	double	z;
	t_vert	attr;

	x = (int) ceil(dt->it_edge0.pos.y - 0.5);
	x_end = (int) ceil(dt->it_edge1.pos.y - 0.5);
	kt_vert_dup(&dt->it_edge0, &dt->i_line);
	dx = dt->it_edge1.pos.x - dt->it_edge0.pos.x;
	dt->di_line.pos.x = (dt->it_edge1.pos.x - dt->i_line.pos.x) / dx;
	dt->di_line.pos.y = (dt->it_edge1.pos.y - dt->i_line.pos.y) / dx;
	dt->di_line.pos.z = (dt->it_edge1.pos.z - dt->i_line.pos.z) / dx;
	dt->i_line.pos.x += dt->di_line.pos.x *
						((double) x + 0.5 - dt->it_edge0.pos.x);
	dt->i_line.pos.y += dt->di_line.pos.y *
						((double) x + 0.5 - dt->it_edge0.pos.x);
	dt->i_line.pos.z += dt->di_line.pos.z *
						((double) x + 0.5 - dt->it_edge0.pos.x);
	while (x < x_end)
	{
		z = 1.0 / dt->i_line.pos.z;
		dt->i_line.pos.x += dt->i_line.pos.x;
		dt->i_line.pos.y += dt->i_line.pos.y;
		dt->i_line.pos.z += dt->i_line.pos.z;
		kt_vert_dup(&dt->i_line, &attr);
		attr.pos.x *= z;
		attr.pos.y *= z;
		attr.pos.z *= z;
		XSetForeground(p->x->dpy, p->x->gc, p->effect->ps.fnc(&(p->effect->ps), &attr));
		XDrawPoint(p->x->dpy, p->x->win, p->x->gc, x, y);
		x++;
	}
}

static void	kt_pipeline_draw_flat_tri(t_pipeline *p, t_drawtri *dt)
{
	int	y;
	int	y_end;

	kt_vert_dup(dt->it0, &dt->it_edge0);
	y = (int) ceil(dt->it0->pos.y - 0.5);
	y_end = (int) ceil(dt->it2->pos.y - 0.5);
	dt->it_edge0.pos.x += dt->dit0.pos.x * ((double) y + 0.5 - dt->it0->pos.y);
	dt->it_edge0.pos.y += dt->dit0.pos.y * ((double) y + 0.5 - dt->it0->pos.y);
	dt->it_edge0.pos.z += dt->dit0.pos.z * ((double) y + 0.5 - dt->it0->pos.y);
	dt->it_edge1.pos.x += dt->dit1.pos.x * ((double) y + 0.5 - dt->it0->pos.y);
	dt->it_edge1.pos.y += dt->dit1.pos.y * ((double) y + 0.5 - dt->it0->pos.y);
	dt->it_edge1.pos.z += dt->dit1.pos.z * ((double) y + 0.5 - dt->it0->pos.y);
	while (y < y_end)
	{
		kt_pipeline_draw_tri_scanline(p, dt, y);
		dt->it_edge0.pos.x += dt->dit0.pos.x;
		dt->it_edge0.pos.y += dt->dit0.pos.y;
		dt->it_edge0.pos.z += dt->dit0.pos.z;
		dt->it_edge1.pos.x += dt->dit1.pos.x;
		dt->it_edge1.pos.y += dt->dit1.pos.y;
		dt->it_edge1.pos.z += dt->dit1.pos.z;
		y++;
	}

}

static void	kt_pipeline_draw_flat_tri_top(t_pipeline *p, t_drawtri *dt)
{
	double	dy;

	dy = dt->it2->pos.y - dt->it0->pos.y;
	kt_vert_dup(dt->it2, &dt->dit0);
	dt->dit0.pos.x -= dt->it0->pos.x;
	dt->dit0.pos.y -= dt->it0->pos.y;
	dt->dit0.pos.z -= dt->it0->pos.z;
	dt->dit0.pos.x /= dy;
	dt->dit0.pos.y /= dy;
	dt->dit0.pos.z /= dy;
	kt_vert_dup(dt->it2, &dt->dit1);
	dt->dit1.pos.x -= dt->it1->pos.x;
	dt->dit1.pos.y -= dt->it1->pos.y;
	dt->dit1.pos.z -= dt->it1->pos.z;
	dt->dit1.pos.x /= dy;
	dt->dit1.pos.y /= dy;
	dt->dit1.pos.z /= dy;
	kt_vert_dup(dt->it1, &dt->it_edge1);
	kt_pipeline_draw_flat_tri(p, dt);
}

static void	kt_pipeline_draw_flat_tri_bottom(t_pipeline *p, t_drawtri *dt)
{
	double	dy;

	dy = dt->it2->pos.y - dt->it0->pos.y;
	kt_vert_dup(dt->it1, &dt->dit0);
	dt->dit0.pos.x -= dt->it0->pos.x;
	dt->dit0.pos.y -= dt->it0->pos.y;
	dt->dit0.pos.z -= dt->it0->pos.z;
	dt->dit0.pos.x /= dy;
	dt->dit0.pos.y /= dy;
	dt->dit0.pos.z /= dy;
	kt_vert_dup(dt->it2, &dt->dit1);
	dt->dit1.pos.x -= dt->it0->pos.x;
	dt->dit1.pos.y -= dt->it0->pos.y;
	dt->dit1.pos.z -= dt->it0->pos.z;
	dt->dit1.pos.x /= dy;
	dt->dit1.pos.y /= dy;
	dt->dit1.pos.z /= dy;
	kt_vert_dup(dt->it0, &dt->it_edge1);
	kt_pipeline_draw_flat_tri(p, dt);
}

void			kt_pipeline_draw_tri(t_pipeline *p, t_tri *tri)
{
	t_drawtri	dt;
	double		alpha_split;
	t_vec3d		vi;

	dt.it0 = &tri->v0;
	dt.it1 = &tri->v1;
	dt.it2 = &tri->v2;
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
		kt_pipeline_draw_flat_tri_top(p, &dt);
	}
	else if (tri->v1.pos.y == tri->v2.pos.y)
	{
		if (tri->v2.pos.x < tri->v1.pos.x)
			kt_vec3d_swap(&tri->v1.pos, &tri->v2.pos);
		kt_pipeline_draw_flat_tri_bottom(p, &dt);
	}
	else
	{
		alpha_split = (tri->v1.pos.y - tri->v0.pos.y) / (tri->v2.pos.y - tri->v0.pos.y);
		vi.x = tri->v0.pos.x + (tri->v2.pos.x - tri->v0.pos.x) * alpha_split;
		vi.y = tri->v0.pos.y + (tri->v2.pos.y - tri->v0.pos.y) * alpha_split;
		if (tri->v1.pos.x < vi.x)
		{
			dt.it0 = &tri->v0;
			dt.it1 = &tri->v1;
			dt.it2->pos = vi;
			kt_pipeline_draw_flat_tri_bottom(p, &dt);
			dt.it0 = &tri->v0;
			dt.it1->pos = vi;
			dt.it2 = &tri->v2;
			kt_pipeline_draw_flat_tri_top(p, &dt);
		}
		else
		{
			dt.it0 = &tri->v0;
			dt.it1->pos = vi;
			dt.it2 = &tri->v2;
			kt_pipeline_draw_flat_tri_bottom(p, &dt);
			dt.it0->pos = vi;
			dt.it1 = &tri->v1;
			dt.it2 = &tri->v2;
			kt_pipeline_draw_flat_tri_top(p, &dt);
		}
	}
}
