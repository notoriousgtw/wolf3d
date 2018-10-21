/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 14:05:41 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "trilist.h"
#include <stdio.h>

void	kt_tri_init(t_tri t, int p0, int p1, int p2)
{
	ft_bzero(t, sizeof(t_tri));
	t[0] = p0;
	t[1] = p1;
	t[2] = p2;
}

void	kt_tri_color(t_tri t, int color)
{
	t[3] = color;
}

void	kt_trilist_init(t_trilist *l, t_vertlist *v)
{
	if (!(l->indices = ft_memalloc(sizeof(t_tri) * 5)))
		ft_error_unknown("wolf3d: ");
	l->verts = v;
	l->arr_len = 5;
	l->list_size = 0;
}

void	kt_trilist_draw(t_trilist *l, t_xvars *x)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
	{
		XSetForeground(x->dpy, x->gc, l->indices[i][3]);
		kt_drawtri3d(x, l->verts->data[l->indices[i][0]],
					  l->verts->data[l->indices[i][1]],
					  l->verts->data[l->indices[i][2]]);
	}
}

void	kt_trilist_color(t_trilist *l, int color)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		l->indices[i][3] = color;
}

void	kt_trilist_print(t_trilist *l)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		printf("%d, %d, %d, %d\n", l->indices[i][0], l->indices[i][1], l->indices[i][2], l->indices[i][3]);
	printf("\n");
}
