/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:44:40 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 01:29:29 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"
#include <stdio.h>

void			kt_vert_init(t_vert *v, double x, double y, double z)
{
	v->pos.x = x;
	v->pos.y = y;
	v->pos.z = z;
	v->attr = NULL;
	v->attr_size = 0;
	v->interpolate_attr = NULL;
	v->print_attr = NULL;
	v->free_attr = NULL;
}

void			kt_vert_dup(const t_vert *v0, t_vert *v1)
{
	v1->pos = v0->pos;
	ft_memcpy(v1->attr, v0->attr, v0->attr_size);
	v1->attr_size = v0->attr_size;
	v1->interpolate_attr = v0->interpolate_attr;
	v1->print_attr = v0->print_attr;
	v1->free_attr = v0->free_attr;
}

void			kt_vert_interpolate(t_vert v0, t_vert v1, double alpha,
									t_vert *v2)
{
	kt_vec3d_interpolate(v0.pos, v1.pos, alpha, &v2->pos);
	if (v0.attr != NULL && v0.interpolate_attr != NULL &&
		kt_vert_comp_type(&v0, &v1) &&
		kt_vert_comp_type(&v0, v2))
		v0.interpolate_attr(v0.attr, v1.attr, v2->attr);
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
				v0->interpolate_attr == v1->interpolate_attr &&
				v0->print_attr == v1->print_attr &&
				v0->free_attr == v1->free_attr)
		return (true);
	else
		return (false);
}
