/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:19:54 by gwood             #+#    #+#             */
/*   Updated: 2018/11/13 17:10:27 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "events.h"
# include "pipeline.h"

typedef struct	s_scenedata
{
	size_t		n_meshes;
	size_t		n_pipelines;
	size_t		n_effects;
	size_t		n_events;
	t_meshdata	*meshes;
	t_pipeline	*pipelines;
	t_effect	*effects;
	t_event		*events;
}				t_scenedata;

#endif
