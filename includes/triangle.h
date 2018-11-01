/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 22:08:12 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 00:05:03 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "graphics.h"

typedef struct	s_tri
{
	t_vert		v0;
	t_vert		v1;
	t_vert		v2;
}				t_tri;

void			kt_tri_init(t_vert *v0, t_vert *v1, t_vert *v2);

#endif
