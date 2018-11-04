/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:44:40 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 19:46:10 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vertex.h"
#include <stdio.h>

void			kt_vert_init(t_vert *v, double x, double y, double z)
{
	v->pos.x = x;
	v->pos.y = y;
	v->pos.z = z;
	v->attr = NULL;
	v->attr_size = 0;
	v->add_attr = NULL;
	v->sub_attr = NULL;
	v->mult_attr = NULL;
	v->div_attr = NULL;
	v->print_attr = NULL;
	v->free_attr = NULL;
}

void			kt_vert_dup(const t_vert *v0, t_vert *v1)
{
	v1->pos = v0->pos;
	if (!(v1->attr = ft_memalloc(v0->attr_size)))
		return ;
	ft_memcpy(v1->attr, v0->attr, v0->attr_size);
	v1->attr_size = v0->attr_size;
	v1->add_attr = v0->add_attr;
	v1->sub_attr = v0->sub_attr;
	v1->mult_attr = v0->mult_attr;
	v1->div_attr = v0->div_attr;
	v1->print_attr = v0->print_attr;
	v1->free_attr = v0->free_attr;
}

void			kt_vert_print(const t_vert *v)
{
	printf("pos: %f, %f, %f", v->pos.x, v->pos.y, v->pos.z);
	if (v->attr != NULL && v->print_attr != NULL)
		v->print_attr(v->attr);
}

t_bool			kt_vert_comp_type(const t_vert *v0, const t_vert *v1)
{
	if (v0->attr == NULL)
	{
		if (v1->attr == NULL)
			return (true);
		else
			return (false);
	}
	else if (v1->attr == NULL)
		return (false);
	else if (v0->attr_size == v1->attr_size &&
				v0->add_attr == v1->add_attr &&
				v0->sub_attr == v1->sub_attr &&
				v0->mult_attr == v1->mult_attr &&
				v0->div_attr == v1->div_attr &&
				v0->print_attr == v1->print_attr &&
				v0->free_attr == v1->free_attr)
		return (true);
	else
		return (false);
}
