/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:30:18 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 12:49:47 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vertex.h"

void			kt_vert_add(const t_vert *v0, const t_vert *v1, t_vert *v2)
{
	v2->pos.x = v0->pos.x + v1->pos.x;
	v2->pos.y = v0->pos.y + v1->pos.y;
	v2->pos.z = v0->pos.z + v1->pos.z;
	if (kt_vert_comp_type(v0, v1) && kt_vert_comp_type(v0, v2)
			&& v0->add_attr != NULL)
		v0->add_attr(v0->attr, v1->attr, v2->attr);
}

void			kt_vert_sub(const t_vert *v0, const t_vert *v1, t_vert *v2)
{
	v2->pos.x = v0->pos.x - v1->pos.x;
	v2->pos.y = v0->pos.y - v1->pos.y;
	v2->pos.z = v0->pos.z - v1->pos.z;
	if (kt_vert_comp_type(v0, v1) && kt_vert_comp_type(v0, v2)
			&& v0->sub_attr != NULL)
		v0->sub_attr(v0->attr, v1->attr, v2->attr);
}

void			kt_vert_mult(const t_vert *v0, double x, t_vert *v1)
{
	v1->pos.x = v0->pos.x * x;
	v1->pos.y = v0->pos.y * x;
	v1->pos.z = v0->pos.z * x;
	if (kt_vert_comp_type(v0, v1) && v0->mult_attr != NULL)
		v0->mult_attr(v0->attr, x, v1->attr);
}

void			kt_vert_div(const t_vert *v0, double x, t_vert *v1)
{
	v1->pos.x = v0->pos.x / x;
	v1->pos.y = v0->pos.y / x;
	v1->pos.z = v0->pos.z / x;
	if (kt_vert_comp_type(v0, v1) && v0->div_attr != NULL)
		v0->div_attr(v0->attr, x, v1->attr);
}
