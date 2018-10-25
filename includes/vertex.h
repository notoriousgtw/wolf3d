/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:27:25 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:02:32 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "graphics.h"

typedef struct	s_vert
{
	t_vec3d	pos;
	t_vec2d	tc;
}				t_vert;

void	kt_vert_print_data(t_vert v);

#endif
