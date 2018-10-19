/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_2d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:43 by gwood             #+#    #+#             */
/*   Updated: 2018/10/18 12:50:35 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_2D_H
# define GFX_2D_H

typedef struct	s_drawline2d
{
	double	m;
	int		step;
	int		dx;
	int		dy;
}				t_drawline2d;

#endif