/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_shader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:01:18 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 17:13:57 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_SHADER_H
# define GEOMETRY_SHADER_H

# include "graphics.h"

void	kt_geometry_shader_default(t_tri *t, t_vert *v0, t_vert *v1,
								   t_vert *v2, ...);

#endif
