/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 13:49:48 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trilist.h"
#include <stdarg.h>

static void	kt_trilist_resize(t_trilist *l)
{
	t_tri	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tri) * l->arr_len * 2)))
		ft_error_unknown("wolf3d: ");
	ft_memcpy(tmp, l->indices, sizeof(t_tri) * l->list_size);
	free(l->indices);
	l->indices = tmp;
	l->arr_len *= 2;
}

static	int	kt_trilist_check_size(t_trilist *l)
{
	return (l->arr_len == l->list_size);
}

void		kt_trilist_add(t_trilist *l, int p0, int p1, int p2)
{
	if (kt_trilist_check_size(l))
		kt_trilist_resize(l);
	l->indices[l->list_size][0] = p0;
	l->indices[l->list_size][1] = p1;
	l->indices[l->list_size][2] = p2;
	l->indices[l->list_size][3] = 0;
	l->list_size++;
}

void		kt_trilist_insert(t_trilist *l, int p0, int p1, int p2, ...)
{
	int		i;
	int		index;
	va_list	args;

	va_start(args, p2);
	index = va_arg(args, int);
	va_end(args);
	if (kt_trilist_check_size(l))
		kt_trilist_resize(l);
	i = l->list_size;
	while (--i >= index)
	{
		l->indices[i + 1][0] = l->indices[i][0];
		l->indices[i + 1][1] = l->indices[i][1];
		l->indices[i + 1][2] = l->indices[i][2];
		l->indices[i + 1][3] = l->indices[i][3];
	}
	l->indices[index][0] = p0;
	l->indices[index][1] = p1;
	l->indices[index][2] = p2;
	l->indices[index][3] = 0;
	l->list_size++;
}
