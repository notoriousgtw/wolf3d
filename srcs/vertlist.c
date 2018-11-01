/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 21:01:43 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "vertlist.h"
#include <stdio.h>

void			kt_vertlist_init(t_vertlist *l)
{
	if (l->data)
		free(l->data);
	if (!(l->data = ft_memalloc(sizeof(t_vec3d) * 5)))
		ft_error_unknown("wolf3d: ");
	l->arr_len = 5;
	l->list_size = 0;
}

void			kt_vertlist_dup(const t_vertlist *l0, t_vertlist *l1)
{
	int			i;

	kt_vertlist_init(l1);
	i = -1;
	while (++i < l0->list_size)
	{
		kt_vertlist_add(l1, l0->data[i].pos.x, l0->data[i].pos.y, l0->data[i].pos.z);
		ft_memcpy(l1->data[i].data, l0->data[i].data, l0->data->data_size);
		l1->data[i].data_size = l0->data->data_size;
		l1->data[i].interpolate_data = l0->data->interpolate_data;
		l1->data[i].print_data = l0->data->print_data;
		l1->data[i].free_data = l0->data->free_data;
	}

}

void			kt_vertlist_print(const t_vertlist *l)
{
	int			i;

	i = -1;
	while (++i < l->list_size)
		kt_vert_print(&l->data[i]);
}
