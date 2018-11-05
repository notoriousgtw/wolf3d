/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:51:57 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 12:21:36 by gwood            ###   ########.fr       */
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
