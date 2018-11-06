/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:01:11 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 15:15:34 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "mesh.h"
# include "triangle.h"
// typedef struct	s_meshdata	t_meshdata;

void			kt_cube_init_plain_quads(double size, t_meshdata *m);
void			kt_cube_init_plain_tris(double size, t_meshdata *m);
void			kt_plane_init_tris(double x, double y, t_meshdata *m);

#endif
