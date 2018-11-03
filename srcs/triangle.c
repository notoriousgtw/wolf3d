/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:11:19 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 14:54:41 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/triangle.h"
#include <stdio.h>

void			kt_tri_init(t_tri *t, const t_vert *v0, const t_vert *v1,
					const t_vert *v2)
{
	if (!kt_vert_comp_type(v0, v1) || !kt_vert_comp_type(v0, v2))
		return ;
	ft_memcpy(&t->v0, v0, sizeof(t_vert));
	ft_memcpy(&t->v1, v1, sizeof(t_vert));
	ft_memcpy(&t->v2, v2, sizeof(t_vert));
	if (v0->attr != NULL)
	{
		t->v0.attr = ft_memalloc(v0->attr_size);
		ft_memcpy(t->v0.attr, v0->attr, v0->attr_size);
		t->v1.attr = ft_memalloc(v1->attr_size);
		ft_memcpy(t->v1.attr, v1->attr, v1->attr_size);
		t->v2.attr = ft_memalloc(v2->attr_size);
		ft_memcpy(t->v2.attr, v2->attr, v2->attr_size);
	}
}

void	kt_tri_print(const t_tri *tri)
{
		kt_vert_print(&tri->v0);
		printf("\n");
		kt_vert_print(&tri->v1);
		printf("\n");
		kt_vert_print(&tri->v2);
		printf("\n");
}
