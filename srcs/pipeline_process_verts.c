/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_process_verts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 21:21:51 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 23:52:30 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline.h"
#include <stdarg.h>

void			kt_pipeline_process_verts(t_pipeline *p,
										  const t_vertlist *verts,
										  const t_indexlist *indices)
{
	int			i;
	t_vertlist	verts_out;

	kt_vertlist_dup(verts, &verts_out);
	i = -1;
	while (++i < verts_out.list_size)
		p->effect.vs.fnc(&(p->effect.ps), &(verts_out.data[i]));
	kt_pipeline_assemble_prims(p, verts, indices);
}

void			kt_pipeline_process_prims(t_pipeline *p, const t_vertlist *verts,
										  t_indexlist *indices)
{
	int		i;
	t_prim	prim;

	i = indices->list_size;
	if (indices->index_count == 3)
	{
		while (--i >= 0)
		{
			kt_prim_init(&prim, -3);
			p->effect.gs.fnc(&(p->effect.gs), &prim, i,
						 verts->data[indices->data[i * 3]],
						 verts->data[indices->data[i * 3 + 1]],
						 verts->data[indices->data[i * 3 + 2]]);
		}
	}
	else if (indices->index_count == 4)
	{
		while (--i >= 0)
		{
			kt_prim_init(&prim, -4);
			p->effect.gs.fnc(&(p->effect.gs), &prim, i,
						 verts->data[indices->data[i * 4]],
						 verts->data[indices->data[i * 4 + 1]],
						 verts->data[indices->data[i * 4 + 2]],
						 verts->data[indices->data[i * 4 + 3]]);
		}
	}
	else
		return ;
	kt_pipeline_assemble_tris(p, &prim);
}
