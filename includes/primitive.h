/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:36:04 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:27:46 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

#include "graphics.h"

typedef struct	s_prim
{
	t_vert	*verts;
	size_t	vert_count;
}				t_prim;

void	kt_prim_init(t_prim *prim, ssize_t vert_count, ...);
void	kt_prim_free(t_prim *prim);
void	kt_prim_to_tri(t_prim *tri, t_tri *t0);
void	kt_quad_to_tri(t_prim *quad, t_tri *t0, t_tri *t1);

#endif
