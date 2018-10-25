/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:05:13 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 20:39:25 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

void	kt_mesh_draw_wire(const t_meshdata *m)
{
	int		i;
	t_vec3d	screen_verts[m->n_verts];

	ft_bzero(screen_verts, sizeof(t_vec3d) * m->n_verts);
	i = -1;
	while (++i < m->n_verts)
	{
		kt_vec3d_screenify(m->x, m->verts[i].pos, &screen_verts[i]);
		// kt_vec3d_print_data(screen_verts[i]);
	}
	// printf("\n");
	i = -1;
	while (++i < m->n_lines)
	{
		XSetForeground(m->x->dpy, m->x->gc, m->lines[i][2]);
		kt_drawline3d(m->x, screen_verts[m->lines[i][0]],
							screen_verts[m->lines[i][1]]);
	}
}

void	kt_mesh_draw_solid(t_meshdata *m)
{
	int		i;
	t_vec3d	screen_verts[m->n_verts];

	kt_mesh_cull(m);
	ft_bzero(screen_verts, sizeof(t_vec3d) * m->n_verts);
	i = -1;
	while (++i < m->n_verts)
	{
		kt_vec3d_screenify(m->x, m->verts[i].pos, &screen_verts[i]);
		// kt_vec3d_print_data(screen_verts[i]);
	}
	// printf("\n");
	i = -1;
	while (++i < m->n_tris)
	{
		if (!m->cull_flags[i])
		{
			XSetForeground(m->x->dpy, m->x->gc, m->tris[i][3]);
			kt_drawtri3d(m->x, screen_verts[m->tris[i][0]],
							   screen_verts[m->tris[i][1]],
							   screen_verts[m->tris[i][2]]);
		}
	}
}

void	kt_mesh_draw_textured(t_meshdata *m)
{
	int		i;
	t_vec3d	screen_verts[m->n_verts];

	kt_mesh_cull(m);
	ft_bzero(screen_verts, sizeof(t_vec3d) * m->n_verts);
	i = -1;
	while (++i < m->n_verts)
	{
		kt_vec3d_screenify(m->x, m->verts[i].pos, &screen_verts[i]);
		// kt_vec3d_print_data(screen_verts[i]);
	}
	// printf("\n");
	i = -1;
	while (++i < m->n_tris)
	{
		if (!m->cull_flags[i])
		{
			XSetForeground(m->x->dpy, m->x->gc, m->tris[i][3]);
			kt_drawtri3d(m->x, screen_verts[m->tris[i][0]],
							   screen_verts[m->tris[i][1]],
							   screen_verts[m->tris[i][2]]);
		}
	}
}
