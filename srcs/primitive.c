/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:40:23 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 14:43:05 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/primitive.h"
#include "stdio.h"

void			kt_prim_init(t_prim *prim, size_t vert_count, t_vert *verts)
{
	int			i;

	if (prim->vert_count != 0 && prim->verts != NULL)
		kt_prim_free(prim);
	else if (vert_count == 0)
	{
		prim->verts = NULL;
		prim->vert_count = 0;
		return ;
	}
	else if (vert_count < 2 || vert_count > 4)
		return ;
	prim->vert_count = vert_count;
	if (!(prim->verts = (t_vert *) ft_memalloc(sizeof(t_vert) * vert_count)))
		return ;
	if (verts == NULL)
		return ;
	i = -1;
	while (++i < (int) vert_count)
		kt_vert_dup(&verts[i], &(prim->verts[i]));
}

void			kt_prim_free(t_prim *prim)
{
	int			i;

	i = -1;
	while (++i < (int) prim->vert_count)
		if (prim->verts[i].free_attr != NULL)
			prim->verts[i].free_attr(prim->verts[i].attr);
	free(prim->verts);
}

void			kt_prim_print(const t_prim *prim)
{
	int			i;

	i = -1;
	while (++i < (int) prim->vert_count)
	{
		kt_vert_print(prim->verts + i);
		printf("\n");
	}
}
