/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 23:23:35 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linelist.h"

static void	kt_linelist_resize(t_linelist *l)
{
	t_line *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_line) * l->arr_len * 2)))
		ft_error_unknown("wolf3d: ");
	ft_memcpy(tmp, l->indices, l->list_size);
	free(l->indices);
	l->indices = tmp;
}

static	int	kt_linelist_check_size(t_linelist *l)
{
	return (l->arr_len == l->list_size);
}

void		kt_linelist_app(t_linelist *l, int v0, int v1)
{
	if (kt_linelist_check_size(l))
		kt_linelist_resize(l);
	l->indices[l->list_size][0] = v0;
	l->indices[l->list_size][1] = v1;
	l->list_size++;
}

void		kt_linelist_add(t_linelist *l, int v0, int v1, int index)
{
	int	i;

	if (kt_linelist_check_size(l))
		kt_linelist_resize(l);
	i = l->list_size;
	while (--i >= index)
	{
		l->indices[i + 1][0] = l->indices[i][0];
		l->indices[i + 1][1] = l->indices[i][1];
	}
	l->indices[index][0] = v0;
	l->indices[index][1] = v1;
	l->list_size++;
}
