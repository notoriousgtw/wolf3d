/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 23:27:15 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "linelist.h"

void	kt_linelist_init(t_linelist *l, t_vertlist *v)
{
	if (!(l->indices = ft_memalloc(sizeof(t_line) * 5)))
		ft_error_unknown("wolf3d: ");
	l->verts = v;
	l->arr_len = 5;
	l->list_size = 0;
}

void	kt_linelist_draw(t_linelist *l, t_xvars *x, int color)
{
	int				i;

	i = -1;
	while (++i < l->list_size)
		kt_drawline3d(x, l->verts->data[l->indices[i][0]],
					  l->verts->data[l->indices[i][1]], color);
}
