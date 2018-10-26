/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 14:40:59 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trilist.h"

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

void	bb_trilist_color(t_trilist *l, int color)
{
	int	i;

	i = -1;
	bb_init_color_table(l->c, color);
	while (++i < l->list_size)
		l->indices[i][3] = l->c->color[i];
}

void	kt_trilist_print_data(const t_trilist *l)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		kt_tri_print_data(l->indices[i]);
}
