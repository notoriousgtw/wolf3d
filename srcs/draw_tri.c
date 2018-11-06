/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:39:53 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 13:36:00 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/triangle.h"
#include <stdio.h>

// static void	kt_draw_tri_scanline(t_xvars *x_vars, t_drawtri *dt, int y, int color)
// {
// 	int		x;
// 	int		x_end;
// 	double	dx;
// 	double	z;
// 	t_vert	tmp;

// 	x = (int) ceil(dt->it_edge0.pos.y - 0.5);
// 	x_end = (int) ceil(dt->it_edge1.pos.y - 0.5);
// 	kt_vert_dup(&dt->it_edge0, &dt->i_line);
// 	dx = dt->it_edge1.pos.x - dt->it_edge0.pos.x;
// 	kt_vert_sub(&dt->it_edge1, &dt->i_line, &tmp);
// 	kt_vert_div(&tmp, dx, &dt->di_line);
// 	kt_vert_mult(&dt->di_line, ((double) x + 0.5 - dt->it_edge0.pos.x), &tmp);
// 	kt_vert_add(&tmp, &dt->i_line, &dt->i_line);
// 	while (x < x_end)
// 	{
// 		z = 1.0 / dt->i_line.pos.z;
// 		kt_vert_dup(&dt->i_line, &tmp);
// 		kt_vert_mult(&tmp, z, &tmp);
// 		XSetForeground(x_vars->dpy, x_vars->gc, color);
// 		XDrawPoint(x_vars->dpy, x_vars->win, x_vars->gc, x, y);
// 		kt_vert_add(&dt->i_line, &dt->di_line, &dt->i_line);
// 		x++;
// 	}
// }

// static void	kt_draw_flat_tri(t_xvars *x_vars, t_drawtri *dt, int color)
// {
// 	int		y;
// 	int		y_end;
// 	t_vert	tmp;

// 	kt_vert_dup(dt->it0, &dt->it_edge0);
// 	kt_vert_dup(dt->it0, &tmp);
// 	y = (int) ceil(dt->it0->pos.y - 0.5);
// 	y_end = (int) ceil(dt->it2->pos.y - 0.5);
// 	kt_vert_mult(&dt->dit0, ((double) y + 0.5 - dt->it0->pos.y), &tmp);
// 	kt_vert_add(&dt->it_edge0, &tmp, &dt->it_edge0);
// 	kt_vert_mult(&dt->dit1, ((double) y + 0.5 - dt->it0->pos.y), &tmp);
// 	kt_vert_add(&dt->it_edge1, &tmp, &dt->it_edge1);
// 	while (y < y_end)
// 	{
// 		kt_draw_tri_scanline(x_vars, dt, y, color);
// 		kt_vert_add(&dt->it_edge0, &dt->dit0, &dt->it_edge0);
// 		kt_vert_add(&dt->it_edge1, &dt->dit1, &dt->it_edge1);
// 		y++;
// 	}

// }

// static void	kt_draw_flat_tri_top(t_xvars *x_vars, t_drawtri *dt, int color)
// {
// 	double	dy;

// 	dy = dt->it2->pos.y - dt->it0->pos.y;
// 	kt_vert_dup(dt->it2, &dt->dit0);
// 	kt_vert_sub(&dt->dit0, dt->it0, &dt->dit0);
// 	kt_vert_div(&dt->dit0, dy, &dt->dit0);
// 	kt_vert_dup(dt->it2, &dt->dit1);
// 	kt_vert_sub(&dt->dit1, dt->it1, &dt->dit1);
// 	kt_vert_div(&dt->dit1, dy, &dt->dit1);
// 	kt_vert_dup(dt->it1, &dt->it_edge1);
// 	kt_draw_flat_tri(x_vars, dt, color);
// }

// static void	kt_draw_flat_tri_bottom(t_xvars *x_vars, t_drawtri *dt, int color)
// {
// 	double	dy;

// 	dy = dt->it2->pos.y - dt->it0->pos.y;
// 	kt_vert_dup(dt->it1, &dt->dit0);
// 	kt_vert_sub(&dt->dit0, dt->it0, &dt->dit0);
// 	kt_vert_div(&dt->dit0, dy, &dt->dit0);
// 	kt_vert_dup(dt->it2, &dt->dit1);
// 	kt_vert_sub(&dt->dit1, dt->it0, &dt->dit1);
// 	kt_vert_div(&dt->dit1, dy, &dt->dit1);
// 	kt_vert_dup(dt->it0, &dt->it_edge1);
// 	kt_draw_flat_tri(x_vars, dt, color);
// }

// void		kt_tri_draw(t_xvars *x_vars, t_tri *tri, int color)
// {
// 	t_drawtri	dt;
// 	double		alpha_split;
// 	t_vert		vi;

// 	dt.it0 = &tri->v0;
// 	dt.it1 = &tri->v1;
// 	dt.it2 = &tri->v2;
// 	if (tri->v1.pos.y < tri->v0.pos.y)
// 		kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
// 	if (tri->v2.pos.y < tri->v1.pos.y)
// 		kt_vec3d_swap(&tri->v1.pos, &tri->v2.pos);
// 	if (tri->v1.pos.y < tri->v0.pos.y)
// 		kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
// 	if (tri->v0.pos.y == tri->v1.pos.y)
// 	{
// 		if (tri->v1.pos.x < tri->v0.pos.x)
// 			kt_vec3d_swap(&tri->v0.pos, &tri->v1.pos);
// 		kt_tri_print(tri);
// 		printf("\n");
// 		kt_draw_flat_tri_top(x_vars, &dt, color);
// 	}
// 	else if (tri->v1.pos.y == tri->v2.pos.y)
// 	{
// 		if (tri->v2.pos.x < tri->v1.pos.x)
// 			kt_vec3d_swap(&tri->v1.pos, &tri->v2.pos);
// 		kt_tri_print(tri);
// 		printf("\n");
// 		kt_draw_flat_tri_bottom(x_vars, &dt, color);
// 	}
// 	else
// 	{
// 		kt_tri_print(tri);
// 		printf("\n");
// 		alpha_split = (tri->v1.pos.y - tri->v0.pos.y) / (tri->v2.pos.y - tri->v0.pos.y);
// 		kt_vert_dup(&tri->v0, &vi);
// 		kt_vert_sub(&tri->v2, &tri->v0, &vi);
// 		kt_vert_mult(&vi, alpha_split, &vi);
// 		kt_vert_add(&tri->v0, &vi, &vi);
// 		if (tri->v1.pos.x < vi.pos.x)
// 		{
// 			dt.it0 = &tri->v0;
// 			dt.it1 = &tri->v1;
// 			dt.it2 = &vi;
// 			kt_draw_flat_tri_bottom(x_vars, &dt, color);
// 			dt.it0 = &tri->v0;
// 			dt.it1 = &vi;
// 			dt.it2 = &tri->v2;
// 			kt_draw_flat_tri_top(x_vars, &dt, color);
// 		}
// 		else
// 		{
// 			dt.it0 = &tri->v0;
// 			dt.it1 = &vi;
// 			dt.it2 = &tri->v2;
// 			// kt_draw_flat_tri_bottom(x_vars, &dt, color);
// 			dt.it0 = &vi;
// 			dt.it1 = &tri->v1;
// 			dt.it2 = &tri->v2;
// 			kt_draw_flat_tri_top(x_vars, &dt, color);
// 		}
// 	}
// }
