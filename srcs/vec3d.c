/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:22 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 21:22:14 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"
#include "../includes/vertlist.h"
#include <stdio.h>

double				bb_vec3d_len(t_vec3d *v)
{
	return (sqrt((v->x * v->x) + (v->y + v->y) + (v->z * v->z)));
}

void				kt_vec3d_swap(t_vec3d *v0, t_vec3d *v1)
{
	t_vec3d			swp;

	swp = *v0;
	*v0 = *v1;
	*v1 = swp;
}

double				kt_vec3d_dotproduct(t_vec3d v0, t_vec3d v1)
{
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

void				kt_vec3d_crossproduct(t_vec3d v0, t_vec3d v1, t_vec3d *v2)
{
	v2->x = v0.y * v1.z - v0.z * v1.y;
	v2->y = v0.z * v1.x - v0.x * v1.z;
	v2->z = v0.x * v1.y - v0.y * v1.x;
}

void				kt_vec3d_interpolate(t_vec3d v0, t_vec3d v1, double alpha,
										t_vec3d *v2)
{
	v2->x = v0.x + (v1.x - v0.x) * alpha;
	v2->y = v0.y + (v1.y - v0.y) * alpha;
	v2->z = v0.z + (v1.z - v0.z) * alpha;
}

void				kt_vec3d_transform(t_vec3d v0, double m[4][4], t_vec3d *v1)
{
	t_vec3d	tmp;

	if (&v0 == v1)
	{
		tmp.x = v0.x * m[0][0] + v0.y * m[1][0] + v0.z * m[2][0] + m[3][0];
		tmp.y = v0.x * m[0][1] + v0.y * m[1][1] + v0.z * m[2][1] + m[3][1];
		tmp.z = v0.x * m[0][2] + v0.y * m[1][2] + v0.z * m[2][2] + m[3][2];
		v1->x = tmp.x;
		v1->y = tmp.y;
		v1->z = tmp.z;
		return ;
	}
	v1->x = v0.x * m[0][0] + v0.y * m[1][0] + v0.z * m[2][0] + m[3][0];
	v1->y = v0.x * m[0][1] + v0.y * m[1][1] + v0.z * m[2][1] + m[3][1];
	v1->z = v0.x * m[0][2] + v0.y * m[1][2] + v0.z * m[2][2] + m[3][2];
}

void				kt_vec3d_screenify(t_xvars *x, t_vec3d v0, t_vec3d *v1)
{
	const double	z_inv = 1.0 / v0.z;

	v1->x = (v0.x * z_inv + 1) * ((double) x->width / 2.0);
	v1->y = (-v0.y * z_inv + 1) * ((double) x->height / 2.0);
}

void				kt_vec3d_print_data(t_vec3d v)
{
	printf("%f, %f, %f", v.x, v.y, v.z);
}
