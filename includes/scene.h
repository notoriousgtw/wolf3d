/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:19:54 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 18:31:07 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "pipeline.h"

typedef struct	s_scenedata
{
	t_meshdata	*meshes;
	t_pipeline	*pipelines;
	t_effect	*effects;
	void		*data;
}				t_scenedata;

void			kt_scenedata_init(t_scenedata *d, t_meshdata *meshes,
								  t_pipeline *pipelines, t_effect *effects);

#endif
