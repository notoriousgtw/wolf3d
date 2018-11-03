/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:22 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:21:30 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"
#include "../includes/vertlist.h"
#include <stdio.h>

void			kt_vec2d_swap(t_vec2d *v0, t_vec2d *v1)
{
	t_vec2d		swp;

	swp = *v0;
	*v0 = *v1;
	*v1 = swp;
}

double			kt_vec2d_dotproduct(t_vec2d v0, t_vec2d v1)
{
	return (v0.x * v1.x + v0.y * v1.y);
}

void			kt_vec2d_interpolate(t_vec2d v0, t_vec2d v1, double alpha,
								 t_vec2d *v2)
{
	v2->x = v0.x + (v1.x - v0.x) * alpha;
	v2->y = v0.y + (v1.y - v0.y) * alpha;
}

void			kt_vec2d_transform(t_vec2d v0, double m[3][3], t_vec2d *v1)
{
	v1->x = v0.x * m[0][0] + v0.y * m[1][0] + m[2][0];
	v1->y = v0.x * m[0][1] + v0.y * m[1][1] + m[2][1];
}

void			kt_vec2d_print_data(t_vec2d v)
{
	printf("%f, %f", v.x, v.y);
}
