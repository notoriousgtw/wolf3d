/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_shaders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:16:09 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 15:17:59 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/effect.h"
#include <stdarg.h>

void	kt_gs_default_init(t_gs *gs)
{
	gs->fnc = kt_gs_default_fnc;
}

void	kt_gs_default_fnc(t_gs *gs, t_prim *prim, size_t index, ...)
{
	int		i;
	va_list	verts;

	i = (int) index;
	if (!(gs))
		ft_error_unknown("wolf3d: ");
	va_start(verts, index);
	i = -1;
	while (++i < (int) prim->vert_count)
		kt_vert_dup(va_arg(verts, t_vert *), &prim->verts[i]);
	va_end(verts);
}
