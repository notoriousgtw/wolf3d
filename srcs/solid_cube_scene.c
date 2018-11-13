/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_cube_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:07:08 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 21:48:42 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "shapes.h"
#include "solid_cube_scene.h"

void	kt_solid_cube_scene_init(t_solid_cube_scene *scene, t_xvars *x,
								 int color)
{
	kt_cube_init_plain_tris(1, &scene->cube);
	kt_pipeline_init(&scene->pipeline, x);
	kt_mat3d_identity(scene->tr);
	kt_tr3d_translate(scene->tr, 0, 0, 2);
	kt_vs_color_init(&scene->effect.vs, scene->tr, WHITE);
	kt_gs_default_init(&scene->effect.gs);
	kt_ps_color_init(&scene->effect.ps);
	scene->data.n_meshes = 1;
	scene->data.meshes = &scene->cube;
	scene->data.n_pipelines = 1;
	scene->data.pipelines = &scene->pipeline;
	scene->data.n_effects = 1;
	scene->data.effects = &scene->effect;
	scene->data.n_events = 0;
	scene->data.events = NULL;
}

void	kt_solid_cube_scene_draw(t_solid_cube_scene *scene, double tr[4][4],
										 int color)
{
kt_vs_color_init5
	scene->effect
	kt_mat3d_mult(&scene->tr, tr, &scene->tr);
	kt_pipeline_draw(&scene->pipeline, &scene->tr);
}
