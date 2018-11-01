/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:51:57 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 15:38:51 by gwood            ###   ########.fr       */
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

void			kt_pipeline_init(t_pipeline *p, t_xvars *x);
void			kt_pipeline_bind_shaders(t_pipeline *p, t_vertex_shader_fnc vs,
									t_geometry_shader_fnc gs,
									t_pixel_shader_fnc ps);
void			kt_pipeline_draw(t_pipeline *p, const t_meshdata *m);
void			kt_pipeline_process_verts(t_pipeline *p, const t_vertlist *v,
								  const t_indexlist *i);
void			kt_pipeline_assemble_tris(t_pipeline *p, const t_vertlist *v,
								  const t_indexlist *i);
void			kt_pipeline_process_tri(t_pipeline *p, t_vert *v0, t_vert *v1,
								t_vert *v2, ...);
void			kt_pipeline_post_process_tri_verts(t_pipeline *p, t_tri *t);
void			kt_pipeline_drawtriangle(t_pipeline *p, t_tri t);

#endif
