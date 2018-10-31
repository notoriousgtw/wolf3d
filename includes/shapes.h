/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:01:11 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 15:45:02 by gwood            ###   ########.fr       */
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
	size_t		tris[12 * 3];
	size_t		quads[6 * 4];
}				t_cube;

void			kt_cube_init(t_cube *c, t_xvars *x, double size);
void			bb_rect_init(t_cube *c, t_xvars *x, double size);

#endif
