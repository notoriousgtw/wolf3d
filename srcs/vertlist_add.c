/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 14:14:00 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertlist.h"

static void	kt_vertlist_resize(t_vertlist *l)
{
	t_vec3d *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_vec3d) * l->arr_len * 2)))
		ft_error_unknown("wolf3d: ");
	ft_memcpy(tmp, l->data, sizeof(t_vec3d) * l->list_size);
	free(l->data);
	l->data = tmp;
	l->arr_len *= 2;
}

static	int	kt_vertlist_check_size(t_vertlist *l)
{
	return (l->arr_len == l->list_size);
}

void		kt_vertlist_app(t_vertlist *l, t_vec3d v)
{
	if (kt_vertlist_check_size(l))
		kt_vertlist_resize(l);
	l->data[l->list_size] = v;
	l->list_size++;
}

void		kt_vertlist_add(t_vertlist *l, t_vec3d v, int index)
{
	int	i;

	if (kt_vertlist_check_size(l))
		kt_vertlist_resize(l);
	i = l->list_size;
	while (--i >= index)
		l->data[i + 1] = l->data[i];
	l->data[index] = v;
	l->list_size++;
}
