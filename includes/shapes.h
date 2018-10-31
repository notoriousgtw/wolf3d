/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:01:11 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 21:47:54 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "graphics.h"
// typedef struct	s_meshdata	t_meshdata;

void			kt_cube_init_plain(double size, t_meshdata *m);
void			bb_rect_init(t_cube *c, t_xvars *x, double size);

#endif
