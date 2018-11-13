/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_cube_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:02:24 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 21:48:39 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLID_CUBE_FORM_H
# define SOLID_CUBE_FORM_H

# include "scene.h"

typedef struct	s_solid_cube_scene
{
	t_scenedata	data;
	t_meshdata	cube;
	t_pipeline	pipeline;
	t_effect	effect;
	double		tr[4][4];
}				t_solid_cube_scene;

void			kt_solid_cube_scene_init(t_solid_cube_scene *scene, t_xvars *x);
void			kt_solid_cube_scene_draw(t_solid_cube_scene *scene,
										 double tr[4][4], int color);

#endif
