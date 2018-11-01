/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:11:19 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 00:42:58 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

void			kt_tri_init(t_tri *t, const t_vert *v0, const t_vert *v1,
					const t_vert *v2)
{
	if (!kt_vert_comp_type(v0, v1) || !kt_vert_comp_type(v0, v2))
		return ;
	ft_memcpy(&t->v0, v0, sizeof(t_vert));
	ft_memcpy(&t->v1, v1, sizeof(t_vert));
	ft_memcpy(&t->v2, v2, sizeof(t_vert));
	if (v0->data != NULL)
	{
		t->v0.data = ft_memalloc(v0->data_size);
		ft_memcpy(t->v0.data, v0->data, v0->data_size);
		t->v1.data = ft_memalloc(v1->data_size);
		ft_memcpy(t->v1.data, v1->data, v1->data_size);
		t->v2.data = ft_memalloc(v2->data_size);
		ft_memcpy(t->v2.data, v2->data, v2->data_size);
	}
}
