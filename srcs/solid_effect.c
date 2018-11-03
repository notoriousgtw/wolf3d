/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 02:47:07 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 13:52:49 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/effect.h"
#include "../includes/vertex.h"
#include "../includes/vector.h"

void	kt_vs_color_init(t_vs *vs, double mat[4][4], int color)
{
	int	*c;

	vs->fnc = kt_vs_color_fnc;
	ft_memcpy(vs->mat, mat, sizeof(double) * 4 * 4);
	if (!(c = ft_memalloc(sizeof(int))))
		return ;
	*c = color;
	vs->data = c;
}

void	kt_vs_color_fnc(t_vs *vs, t_vert *vert)
{
	vert->attr = vs->data;
	kt_vec3d_transform(vert->pos, vs->mat, &vert->pos);
}

void	kt_ps_color_init(t_ps *ps)
{
	ps->fnc = kt_ps_color_fnc;
}

int		kt_ps_color_fnc(t_ps *ps, const t_vert *attr)
{
	if (!(ps))
		ft_error_unknown("wolf3d: ");
	return (*(int*) attr->attr);
}
