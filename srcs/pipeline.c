/* ************************************************************************** */
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

#include "../includes/pipeline.h"

void			kt_pipeline_init(t_pipeline *p, t_xvars *x)
{
	p->x = x;
}

void			kt_pipeline_bind_effect(t_pipeline *p, t_vs_fnc vs,
											t_gs_fnc gs, t_ps_fnc ps)
{
	p->effect->vs.fnc = vs;
	p->effect->gs.fnc = gs;
	p->effect->ps.fnc = ps;
}

void			kt_pipeline_draw(t_pipeline *p, const t_meshdata *m)
{
	kt_pipeline_process_verts(p, &m->verts, &m->indices);
}
