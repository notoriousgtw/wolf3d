/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:51:57 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 05:06:04 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include "effect.h"
# include "mesh.h"
# include "primitive.h"
# include "triangle.h"

typedef struct	s_pipeline
{
	t_xvars		*x;
	t_effect	*effect;
}				t_pipeline;

typedef struct	s_drawtri
{
	t_vert		*it0;
	t_vert		*it1;
	t_vert		*it2;
	t_vert		dit0;
	t_vert		dit1;
	t_vert		it_edge0;
	t_vert		it_edge1;
	t_vert		i_line;
	t_vert		di_line;
	t_vert		attr;
}				t_drawtri;

void			kt_pipeline_init(t_pipeline *p, t_xvars *x);
// void			kt_pipeline_bind_effect(t_pipeline *p, t_vs_fnc vs,
// 											t_gs_fnc gs, t_ps_fnc ps);
void			kt_pipeline_draw(t_pipeline *p, const t_meshdata *m);
void			kt_pipeline_process_verts(t_pipeline *p,
											const t_vertlist *verts,
											const t_indexlist *indices);
void			kt_pipeline_process_prims(t_pipeline *p,
											const t_vertlist *verts,
											const t_indexlist *indices);
void			kt_pipeline_assemble_tris(t_pipeline *p, t_prim *prim);
void			kt_pipeline_process_tri(t_pipeline *p, t_tri *tri);
void			kt_pipeline_draw_tri(t_pipeline *p, t_tri *tri);

#endif
