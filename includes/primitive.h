/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:36:04 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 04:43:12 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVE_H
# define PRIMITIVE_H

# include "vertex.h"

typedef struct	s_prim
{
	t_vert		*verts;
	size_t		vert_count;
}				t_prim;

void			kt_prim_init(t_prim *prim, size_t vert_count, t_vert *verts);
void			kt_prim_free(t_prim *prim);

#endif
