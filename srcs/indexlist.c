/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 14:27:42 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "indexlist.h"
#include <stdio.h>

void	kt_indexlist_init(t_indexlist *l, size_t index_count)
{
	if (index_count < 1)
		return ;
	if (!(l->data = ft_memalloc(sizeof(size_t) * 5 * index_count)))
		ft_error_unknown("wolf3d: ");
	l->index_count = index_count;
	l->arr_len = 15;
	l->list_size = 0;
}

void	kt_indexlist_print_data(const t_indexlist *l)
{
	int	i;

	i = -1;
	while (++i < l->list_size)
		printf("v%d, v%d, v%d\n", l->data[i * l->index_count],
					 l->data[i * l->index_count + 1],
					 l->data[i * l->index_count + 2]);
}
