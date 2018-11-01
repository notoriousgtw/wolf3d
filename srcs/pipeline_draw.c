/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:43:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 15:26:42 by gwood            ###   ########.fr       */
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
		p->effect.vs(&(verts_out.data[i]));
	kt_pipeline_assemble_tris(p, &verts_out, indices);
}

static t_bool	kt_cull_tri(t_vec3d v0, t_vec3d v1, t_vec3d v2)
{
	t_vec3d 	norm;

	v1.x -= v0.x;
	v1.y -= v0.y;
	v1.z -= v0.z;
	v2.x -= v0.x;
	v2.y -= v0.y;
	v2.z -= v0.z;
	kt_vec3d_crossproduct(v1, v2, &norm);
	if (kt_vec3d_dotproduct(norm, v0) <= 0.0)
		return (true);
	else
		return (false);
}

void			kt_pipeline_assemble_tris(t_pipeline *p,
										  const t_vertlist *verts,
										  const t_indexlist *indices)
{
	int			i;
	t_vert		v0;
	t_vert		v1;
	t_vert		v2;
	t_vert		tmp;

	i = -1;
	while (++i < indices->list_size)
	{
		kt_vert_dup(&(verts->data[indices->data[i * 3]]), &v0);
		kt_vert_dup(&(verts->data[indices->data[i * 3 + 1]]), &v1);
		kt_vert_dup(&(verts->data[indices->data[i * 3 + 2]]), &v2);
		if (kt_cull_tri(v0.pos, v1.pos, v2.pos))
			kt_pipeline_process_tri(p, &v0, &v1, &v2, i);
	}
}

void			kt_pipeline_process_tri(t_pipeline *p, t_vert *v0, t_vert *v1,
										t_vert *v2, ...)
{
	t_tri		tri;
	va_list		ap;

	va_start(ap, v2);
	p->effect.gs(&tri, v0, v1, v2, va_arg(ap, size_t));
	va_end(ap);
	kt_pipeline_post_process_tri_verts(p, &tri);
}

void			kt_pipeline_post_process_tri_verts(t_pipeline *p, t_tri *tri)
{
	kt_vec3d_screenify(p->x, tri->v0.pos, &(tri->v0.pos));
	kt_vec3d_screenify(p->x, tri->v1.pos, &(tri->v1.pos));
	kt_vec3d_screenify(p->x, tri->v2.pos, &(tri->v2.pos));
	kt_pipeline_drawtriangle(p, *tri);
}
