/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 02:47:07 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 03:01:12 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "effect.h"

void	kt_vs_color_init(t_vs *vs, double mat[4][4], int color)
{
	int	*c;

	vs->fnc = kt_vs_color_fnc;
	ft_memcpy(vs->mat, mat, sizeof(double) * 4);
	if (!(c = ft_memalloc(sizeof(int))))
		return ;
	*c = color;
	vs->data = c;
}

void	kt_vs_color_fnc(t_vs *vs, t_vert *vert)
{
	vert->attr = vs->data;
	kt_vert_transform(vert, vs->mat);
}

void	kt_ps_color_init(t_ps *ps)
{
	ps->fnc = kt_ps_color_fnc;
}

int		kt_ps_color_fnc(t_ps *ps, const t_vert *attr)
{
	return (*(int *)attr->attr);
}
