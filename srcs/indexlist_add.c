/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexlist_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 15:53:31 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "indexlist.h"
#include <stdarg.h>

static void		kt_indexlist_resize(t_indexlist *l)
{
	size_t		*tmp;

	l->arr_len *= 2;
	if (!(tmp = ft_memalloc(sizeof(size_t) * l->arr_len)))
		ft_error_unknown("wolf3d: ");
	ft_bzero(tmp, sizeof(size_t) * l->arr_len);
	ft_memcpy(tmp, l->data, sizeof(size_t) * l->list_size * l->index_count);
	free(l->data);
	l->data = tmp;
}

static int		kt_indexlist_check_size(t_indexlist *l)
{
	return (l->list_size * l->index_count - l->arr_len < l->index_count);
}

void			kt_indexlist_add(t_indexlist *l, ...)
{
	int			i;
	va_list		ap;

	if (kt_indexlist_check_size(l))
		kt_indexlist_resize(l);
		va_start(ap, l);
	i = -1;
	while (++i < (int) l->index_count)
		l->data[l->list_size * l->index_count + i] = va_arg(ap, size_t);
	l->list_size++;
}

void			kt_indexlist_insert(t_indexlist *l, size_t index, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, index);
	if (kt_indexlist_check_size(l))
		kt_indexlist_resize(l);
	i = l->list_size * l->index_count;
	while (--i >= index)
		l->data[i + 1] = l->data[i];
	i = -1;
	while (++i < (int) l->index_count)
		l->data[l->list_size * l->index_count + i] = va_arg(ap, size_t);
	va_end(ap);
	l->list_size++;
}
