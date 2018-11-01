// }

static void 		kt_cube_init_tri(t_cube *c)/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:29:13 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 01:31:56 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipeline.h"

void			kt_pipeline_init(t_pipeline *p, t_xvars *x)
{
	p->x = x;
}

void			kt_pipeline_bind_shaders(t_pipeline *p, t_vertex_shader_fnc vs,
									t_geometry_shader_fnc gs,
									t_pixel_shader_fnc ps)
{
	p->effect.vs = vs;
	p->effect.gs = gs;
	p->effect.ps = ps;
}

void			kt_pipeline_draw(t_pipeline *p, const t_meshdata *m)
{
	kt_pipeline_process_verts(p, m->verts, m->indices);
}
