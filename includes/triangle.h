/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:08:12 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 14:50:37 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "vertex.h"

typedef struct	s_tri
{
	t_vert		v0;
	t_vert		v1;
	t_vert		v2;
}				t_tri;

void			kt_tri_init(t_tri *tri, const t_vert *v0, const t_vert *v1,
								const t_vert *v2);
void			kt_tri_print(const t_tri *tri);

#endif
