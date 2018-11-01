/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:51:57 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:31:22 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include "graphics.h"

typedef struct	s_pipeline
{
	t_xvars		*x;
	t_effect	effect;
}				t_pipeline;

typedef struct	s_drawtri
{

}				t_drawtri;

void	kt_pipeline_init(t_pipeline *p, t_xvars *x);
void	kt_pipeline_bind_shaders(t_pipeline *p, t_vs *vs, t_gs *gs, t_ps *ps);
void	kt_pipeline_draw(t_pipeline *p, const t_meshdata *m);
void	kt_pipeline_process_verts(t_pipeline *p, const t_vertlist *verts,
								  const t_indexlist *indices);
void	kt_pipeline_process_prims(t_pipeline *p, const t_vertlist *verts,
								  const t_indexlist *indices);
void	kt_pipeline_assemble_tris(t_pipeline *p, t_prim *prim);
void	kt_pipeline_process_tri(t_pipeline *p, t_tri *tri);
void	kt_pipeline_drawtriangle(t_pipeline *p, t_tri *tri);

#endif
