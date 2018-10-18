/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:22 by gwood             #+#    #+#             */
/*   Updated: 2018/10/17 19:12:58 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

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
