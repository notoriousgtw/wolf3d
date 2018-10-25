/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:43:44 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:12:17 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "graphics.h"

typedef struct s_vert	t_vert;

typedef struct			s_meshdata
{
	t_xvars	*x;
	int		n_verts;
	int		n_lines;
	int		n_tris;
	t_vert	*verts;
	t_line	*lines;
	t_tri	*tris;
	t_bool	*cull_flags;
}						t_meshdata;

void					kt_mesh_color(t_meshdata *m, int color);
void					kt_mesh_transform(t_meshdata *m, double mat[4][4]);
void					kt_mesh_print_data(const t_meshdata *m);
void					kt_mesh_cull(t_meshdata *m);
void					kt_mesh_draw_wire(const t_meshdata *m);
void					kt_mesh_draw_solid(t_meshdata *m);

#endif
