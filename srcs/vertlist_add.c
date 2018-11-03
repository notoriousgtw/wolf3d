/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 17:41:54 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vertlist.h"
#include <stdarg.h>

static void			kt_vertlist_resize(t_vertlist *l)
{
	t_vert 		*tmp;

	l->arr_len *= 2;
	if (!(tmp = ft_memalloc(sizeof(t_vert) * l->arr_len)))
		ft_error_unknown("wolf3d: ");
	ft_memcpy(tmp, l->data, sizeof(t_vert) * l->list_size);
	l->data = tmp;
}

static int			kt_vertlist_check_size(t_vertlist *l)
{
	return (l->arr_len == l->list_size);
}

void		kt_vertlist_add(t_vertlist *l, double x, double y, double z)
{
	if (kt_vertlist_check_size(l))
		kt_vertlist_resize(l);
	kt_vert_init(&(l->data[l->list_size]), x, y, z);
	l->list_size++;
}

void		kt_vertlist_insert(t_vertlist *l, size_t index, ...)
{
	int		i;
	va_list	ap;
	double	x;
	double	y;
	double	z;

	va_start(ap, index);
	x = va_arg(ap, double);
	y = va_arg(ap, double);
	z = va_arg(ap, double);
	va_end(ap);
	if (kt_vertlist_check_size(l))
		kt_vertlist_resize(l);
	i = l->list_size;
	while (--i >= (int)index)
		l->data[i + 1] = l->data[i];
	kt_vert_init(&(l->data[index]), x, y, z);
	l->list_size++;
}
