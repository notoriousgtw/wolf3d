/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:08:12 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 12:42:36 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "graphics.h"
# include "vertex.h"

typedef struct	s_tri
{
	t_vert		v0;
	t_vert		v1;
	t_vert		v2;
}				t_tri;

typedef struct	s_drawtri
{
	t_vert		*it0;
	t_vert		*it1;
	t_vert		*it2;
	t_vert		dit0;
	t_vert		dit1;
	t_vert		it_edge0;
	t_vert		it_edge1;
	t_vert		i_line;
	t_vert		di_line;
}				t_drawtri;

void			kt_tri_init(t_tri *tri, const t_vert *v0, const t_vert *v1,
								const t_vert *v2);
void			kt_tri_print(const t_tri *tri);
void			kt_tri_cdraw(t_xvars *x_vars, t_tri *tri, int color);

#endif
