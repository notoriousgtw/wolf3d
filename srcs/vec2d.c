/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:22 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 16:17:40 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

void		kt_vec2d_swap(t_vec2d *v0, t_vec2d *v1)
{
	t_vec2d	swp;

	swp = *v0;
	*v0 = *v1;
	*v1 = swp;
}

double		kt_vec2d_dotproduct(t_vec2d v0, t_vec2d v1)
{
	return (v0.x * v1.x + v0.y * v1.y);
}

void		kt_vec2d_transform(t_vec2d v0, double m[3][3], t_vec2d *v1)
{
	v1->x = v0.x * m[0][0] + v0.y * m[1][0] + m[2][0];
	v1->y = v0.x * m[0][1] + v0.y * m[1][1] + m[2][1];
}

/*
** @brief	converts from t_vec2d to t_vec2d_i
**
** @param v0 input vector
** @param v1 output vector
** @param r rounding:
**	0 floor
++	1 normal
++	2 ceiling
*/
void		kt_vec2d_ftoi(t_vec2d v0, t_vec2d_i *v1, int r)
{
	if (r == 0)
	{
		v1->x = (int) floor(v0.x);
		v1->y = (int) floor(v0.y);
	}
	else if (r == 1)
	{
		v1->x = (int) round(v0.x);
		v1->y = (int) round(v0.y);
	}
	else if (r == 2)
	{
		v1->x = (int) ceil(v0.x);
		v1->y = (int) ceil(v0.y);
	}
}
