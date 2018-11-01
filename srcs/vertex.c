/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:44:40 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:54:58 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"
#include <stdio.h>

void			kt_vert_init(t_vert *v, double x, double y, double z)
{
	v->pos.x = x;
	v->pos.y = y;
	v->pos.z = z;
	v->data = NULL;
	v->data_size = 0;
	v->interpolate_data = NULL;
	v->print_data = NULL;
	v->free_data = NULL;
}

void			kt_vert_dup(const t_vert *v0, t_vert *v1)
{
	v1->pos = v0->pos;
	ft_memcpy(v1->data, v0->data, v0->data_size);
	v1->data_size = v0->data_size;
	v1->interpolate_data = v0->interpolate_data;
	v1->print_data = v0->print_data;
	v1->free_data = v0->free_data;
}

void			kt_vert_interpolate(t_vert v0, t_vert v1, double alpha,
									t_vert *v2)
{
	kt_vec3d_interpolate(v0.pos, v1.pos, alpha, &v2->pos);
	if (v0.data != NULL && v0.interpolate_data != NULL &&
		kt_vert_comp_type(&v0, &v1) &&
		kt_vert_comp_type(&v0, v2))
		v0.interpolate_data(v0.data, v1.data, v2->data);
}

void			kt_vert_print(const t_vert *v)
{
	printf("pos: %f, %f, %f", v->pos.x, v->pos.y, v->pos.z);
	if (v->data != NULL && v->print_data != NULL)
		v->print_data(v->data);
}

t_bool			kt_vert_comp_type(const t_vert *v0, const t_vert *v1)
{
	if (v0->data == NULL)
	{
		if (v1->data == NULL)
			return (true);
		else
			return (false);
	}
	else if (v1->data == NULL)
		return (false);
	else if (v0->data_size == v1->data_size &&
				v0->interpolate_data == v1->interpolate_data &&
				v0->print_data == v1->print_data &&
				v0->free_data == v1->free_data)
		return (true);
	else
		return (false);
}
