/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_process_verts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 21:21:51 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 15:37:11 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipeline.h"
#include <stdio.h>

void			kt_pipeline_process_verts(t_pipeline *p,
											const t_vertlist *verts,
											const t_indexlist *indices)
{
	int			i;
	t_vertlist	verts_out;

	kt_vertlist_dup(verts, &verts_out);
	i = -1;
	while (++i < verts_out.list_size)
		p->effect->vs.fnc(&(p->effect->vs), &(verts_out.data[i]));
	printf("\n");
	// kt_vertlist_print(verts);
	kt_pipeline_process_prims(p, &verts_out, indices);
}

void			kt_pipeline_process_prims(t_pipeline *p, 
											const t_vertlist *verts,
											const t_indexlist *indices)
{
	int			i;
	t_prim		prim;

	prim.vert_count = 0;
	prim.verts = NULL;
	i = -1;
	if (indices->index_count == 3)
	{
		while (++i < indices->list_size)
		{
			kt_prim_init(&prim, 3, NULL);
			p->effect->gs.fnc(&p->effect->gs, &prim, i,
								&verts->data[indices->data[i]],
								&verts->data[indices->data[i + 1]],
								&verts->data[indices->data[i + 2]]);
			kt_pipeline_assemble_tris(p, &prim);
		}
	}
	else if (indices->index_count == 4)
	{
		while (++i < indices->list_size)
		{
			kt_prim_init(&prim, 4, NULL);
			p->effect->gs.fnc(&p->effect->gs, &prim, i,
								&verts->data[indices->data[i]],
								&verts->data[indices->data[i + 1]],
								&verts->data[indices->data[i + 2]],
								&verts->data[indices->data[i + 3]]);
			kt_pipeline_assemble_tris(p, &prim);
		}
	}
}
