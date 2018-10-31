/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/29 22:52:13 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trilist.h"
#include <stdarg.h>

static void	kt_trilist_resize(t_trilist *l)
{
	size_t	*tmp;

	l->arr_len *= 2;
	if (!(tmp = ft_memalloc(sizeof(size_t) * l->arr_len)))
		ft_error_unknown("wolf3d: ");
	ft_bzero(tmp, sizeof(size_t) * l->arr_len);
	ft_memcpy(tmp, l->indices, sizeof(size_t) * l->list_size * 3);
	free(l->indices);
	l->indices = tmp;
}

static	int	kt_trilist_check_size(t_trilist *l)
{
	return (l->list_size * 3 - l->arr_len < 3);
}

void		kt_trilist_add(t_trilist *l, size_t p0, size_t p1, size_t p2)
{
	if (kt_trilist_check_size(l))
		kt_trilist_resize(l);
	l->indices[l->list_size * 3] = p0;
	l->indices[l->list_size * 3 + 1] = p1;
	l->indices[l->list_size * 3 + 2] = p2;
	l->list_size++;
}

void		kt_trilist_insert(t_trilist *l, size_t p0, size_t p1, size_t p2, ...)
{
	int		i;
	int		index;
	va_list	args;

	va_start(args, p2);
	index = va_arg(args, int);
	va_end(args);
	if (kt_trilist_check_size(l))
		kt_trilist_resize(l);
	i = l->list_size * 3;
	while (--i >= index)
		l->indices[i + 1] = l->indices[i];
	l->indices[index * 3] = p0;
	l->indices[index * 3 + 1] = p1;
	l->indices[index * 3 + 2] = p2;
	l->list_size++;
}
