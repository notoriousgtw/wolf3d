/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 20:01:49 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"
#include "../includes/vertlist.h"
#include <stdio.h>

void			kt_vertlist_init(t_vertlist *l)
{
	if (!(l->data = ft_memalloc(sizeof(t_vert) * 5)))
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
		ft_memcpy(l1->data[i].attr, l0->data[i].attr, l0->data->attr_size);
		l1->data[i].attr_size = l0->data->attr_size;
		l1->data[i].add_attr = l0->data->add_attr;
		l1->data[i].sub_attr = l0->data->sub_attr;
		l1->data[i].mult_attr = l0->data->mult_attr;
		l1->data[i].div_attr = l0->data->div_attr;
		l1->data[i].print_attr = l0->data->print_attr;
		l1->data[i].free_attr = l0->data->free_attr;
	}

}

void			kt_vertlist_print(const t_vertlist *l)
{
	int			i;

	i = -1;
	while (++i < l->list_size)
	{
		kt_vert_print(&l->data[i]);
		printf("\n");
	}
}
