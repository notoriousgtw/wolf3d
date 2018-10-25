/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:44:40 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:13:58 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vertex.h"
#include <stdio.h>

void	kt_vert_interpolate(t_vert v0, t_vert v1, double alpha, t_vert *v2)
{
	kt_vec3d_interpolate(v0.pos, v1.pos, alpha, &v2->pos);
	kt_vec2d_interpolate(v0.tc, v1.tc, alpha, &v2->tc);
}

void	kt_vert_print_data(t_vert v)
{
	printf("pos: %f, %f, %f tc: %f, %f", v.pos.x, v.pos.y, v.pos.z, v.tc.x, v.tc.y);
}
