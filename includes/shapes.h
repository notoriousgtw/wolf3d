/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:01:11 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:03:06 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "graphics.h"
// typedef struct	s_meshdata	t_meshdata;

typedef struct	s_cube
{
	t_meshdata	data;
	t_vert		verts[8];
	t_line		lines[12];
	t_tri		tris[12];
	t_bool		cull_flags[12];
}				t_cube;

void	kt_cube_init(t_cube *c, t_xvars *x, double size);

#endif
