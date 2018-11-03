/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 02:47:07 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 15:45:47 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/effect.h"
#include "../includes/vertex.h"
#include "../includes/vector.h"
#include <stdio.h>

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
	kt_vert_bind_data(vert, vs->data, sizeof(vs->data));
	vert->print_attr = (t_vert_attr_print) kt_vert_color_print;
	kt_vec3d_transform(vert->pos, vs->mat, &vert->pos);
	kt_vert_print(vert);
	printf("\n");
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
