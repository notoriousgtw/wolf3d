/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_shaders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:16:09 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 02:53:06 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/effect.h"

void	kt_gs_default_init(t_gs *gs)
{
	gs->fnc = kt_gs_default_fnc;
}

void	kt_gs_default_fnc(t_gs *gs, t_prim *prim, size_t index, t_vert *verts)
{
	int		i;

	i = (int) index;
	if (!(gs))
		ft_error_unknown("wolf3d: ");
	i = -1;
	while (++i < (int) prim->vert_count)
		kt_vert_dup(&verts[i], &prim->verts[i]);
}
