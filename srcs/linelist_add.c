/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:11:21 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linelist.h"

static void	kt_linelist_resize(t_linelist *l)
{
	t_line *tmp;

	l->arr_len *= 2;
	if (!(tmp = ft_memalloc(sizeof(t_line) * l->arr_len)))
		ft_error_unknown("wolf3d: ");
	ft_memcpy(tmp, l->indices, sizeof(t_line) * l->list_size);
	free(l->indices);
	l->indices = tmp;
}

static	int	kt_linelist_check_size(t_linelist *l)
{
	return (l->arr_len == l->list_size);
}

void		kt_linelist_add(t_linelist *l, int p0, int p1)
{
	if (kt_linelist_check_size(l))
		kt_linelist_resize(l);
	l->indices[l->list_size][0] = p0;
	l->indices[l->list_size][1] = p1;
	l->indices[l->list_size][2] = 0;
	l->list_size++;
}

void		kt_linelist_insert(t_linelist *l, int p0, int p1, int index)
{
	int	i;

	if (kt_linelist_check_size(l))
		kt_linelist_resize(l);
	i = l->list_size;
	while (--i >= index)
	{
		l->indices[i + 1][0] = l->indices[i][0];
		l->indices[i + 1][1] = l->indices[i][1];
		l->indices[i + 1][2] = l->indices[i][2];
	}
	l->indices[index][0] = p0;
	l->indices[index][1] = p1;
	l->indices[index][2] = 0;
	l->list_size++;
}
