/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_process_tris.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:43:38 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 22:39:24 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipeline.h"
#include <stdio.h>

static t_bool	kt_pipeline_cull_tri(t_pipeline *p, t_tri tri)
{
	t_vec3d		v0;
	t_vec3d		v1;
	t_vec3d		v2;
	t_vec3d 	norm;

	kt_vec3d_screenify(p->x, tri.v0.pos, &v0);
	kt_vec3d_screenify(p->x, tri.v1.pos, &v1);
	kt_vec3d_screenify(p->x, tri.v2.pos, &v2);
	kt_tri_print(&tri);
	printf("\n");
	tri.v1.pos.x -= tri.v0.pos.x;
	tri.v1.pos.y -= tri.v0.pos.y;
	tri.v1.pos.z -= tri.v0.pos.z;
	tri.v2.pos.x -= tri.v0.pos.x;
	tri.v2.pos.y -= tri.v0.pos.y;
	tri.v2.pos.z -= tri.v0.pos.z;
	kt_vec3d_crossproduct(tri.v1.pos, tri.v2.pos, &norm);
	if (kt_vec3d_dotproduct(norm, tri.v0.pos) <= 0.0)
	{
		return (true);
	}
	else
	{
		// kt_drawline3d(p->x, v0, v1, DGREY);
		// kt_drawline3d(p->x, v1, v2, DGREY);
		// kt_drawline3d(p->x, v2, v0, DGREY);
		return (false);
	}
}

void			kt_pipeline_assemble_tris(t_pipeline *p, t_prim *prim)
{
	int			i;
	int			tri_count;
	t_tri		*tris;

	tri_count = 0;
	if (prim->vert_count == 3)
	{
		tri_count = 1;
		if (!(tris = (t_tri *) ft_memalloc(sizeof(t_tri) * tri_count)))
			return ;
		kt_tri_init(tris, &prim->verts[0], &prim->verts[1], &prim->verts[2]);
	}
	else if (prim->vert_count == 4)
	{
		tri_count = 2;
		if (!(tris = (t_tri *) ft_memalloc(sizeof(t_tri) * tri_count)))
			return ;
		// kt_prim_print(prim);
		kt_tri_init(tris, &prim->verts[0], &prim->verts[1], &prim->verts[2]);
		kt_tri_init(&tris[1], &prim->verts[1], &prim->verts[3],
					&prim->verts[2]);
		// printf("\n");
		// kt_tri_print(tris);
		// printf("\n");
		// kt_tri_print(tris + 1);
		// printf("\n\n");
	}
	i = -1;
	while (++i < tri_count && kt_pipeline_cull_tri(p, tris[i]))
	{
		kt_pipeline_process_tri(p, &tris[i]);
	}
}

void			kt_pipeline_process_tri(t_pipeline *p, t_tri *tri)
{
	kt_vec3d_screenify(p->x, tri->v0.pos, &(tri->v0.pos));
	kt_vec3d_screenify(p->x, tri->v1.pos, &(tri->v1.pos));
	kt_vec3d_screenify(p->x, tri->v2.pos, &(tri->v2.pos));
	// kt_tri_print(tri);
	// printf("\n");
	kt_pipeline_draw_tri(p, tri);
}
