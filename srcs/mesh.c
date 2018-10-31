/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:49:35 by gwood             #+#    #+#             */
/*   Updated: 2018/10/29 22:02:33 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdio.h>

void	kt_mesh_color(t_meshdata *m, int color)
{
	int i;

	i = -1;
	while (++i < m->n_lines)
		bb_line_color(m->lines[i], color);
	i = -1;
	while (++i < m->n_tris)
		bb_tri_color(m->tris[i], color);
}

void	kt_mesh_transform(t_meshdata *m, double mat[4][4])
{
	int i;

	i = -1;
	while (++i < m->n_verts)
		kt_vec3d_transform(m->verts[i].pos, mat, &m->verts[i].pos);
}

void	kt_mesh_print_data(const t_meshdata *m)
{
	int i;

	printf("verts:\n");
	i = -1;
	while (++i < m->n_verts)
	{
		printf("\tv%d: ", i);
		kt_vert_print_data(m->verts[i]);
		printf("\n");
	}
	printf("\nlines:\n");
	i = -1;
	while (++i < m->n_lines)
	{
		printf("\tl%d: ", i);
		kt_line_print_data(m->lines[i]);
		printf("\n");
	}
	printf("\ntris:\n");
	i = -1;
	while (++i < m->n_tris)
	{
		printf("\tt%d: ", i);
		kt_indexlist_print_data(m->tris[i]);
		printf("\n");
	}
}

void	kt_mesh_cull(t_meshdata *m)
{
	int		i;
	t_vec3d	v0;
	t_vec3d	v1;
	t_vec3d	v2;
	t_vec3d	tmp;

	i = -1;
	while (++i < m->n_tris)
	{
		v0 = (m->verts[m->tris[i][0]].pos);
		v1 = (m->verts[m->tris[i][1]].pos);
		v2 = (m->verts[m->tris[i][2]].pos);
		v1.x -= v0.x;
		v1.y -= v0.y;
		v1.z -= v0.z;
		v2.x -= v0.x;
		v2.y -= v0.y;
		v2.z -= v0.z;
		kt_vec3d_crossproduct(v1, v2, &tmp);
		if (kt_vec3d_dotproduct(tmp, v0) >= 0)
			m->cull_flags[i] = true;
		else
			m->cull_flags[i] = false;
	}
}
