/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:31:40 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 21:04:49 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	kt_scenedata_init(t_scenedata *scene, t_meshdata *meshes,
								  t_pipeline *pipelines, t_effect *effects)
{
	scene->meshes = meshes;
	scene->pipelines = pipelines;
	scene->effects = effects;
}
