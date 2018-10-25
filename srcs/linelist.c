/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 14:40:28 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "linelist.h"
#include <stdio.h>

void	kt_linelist_init(t_linelist *l, t_vertlist *v)
{
	if (!(l->indices = ft_memalloc(sizeof(t_line) * 5)))
		ft_error_unknown("wolf3d: ");
	l->verts = v;
	l->arr_len = 5;
	l->list_size = 0;
}

void	kt_linelist_draw(t_linelist *l, t_xvars *x)
{
	int				i;

	i = -1;
	while (++i < l->list_size)
	{
		XSetForeground(x->dpy, x->gc, l->indices[i][2]);
		kt_drawline3d(x, l->verts->data[l->indices[i][0]],
						l->verts->data[l->indices[i][1]]);
	}
}

void	kt_linelist_color(t_linelist *l, int color)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		l->indices[i][2] = color;
}

void	kt_linelist_print_data(const t_linelist *l)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		kt_line_print_data(l->indices[i]);
}
