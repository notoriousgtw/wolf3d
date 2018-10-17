/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:43 by gwood             #+#    #+#             */
/*   Updated: 2018/10/17 14:58:14 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"

typedef struct	s_vec2d
{
	double x;
	double y;
}				t_vec2d;

typedef struct	s_vec3d
{
	double x;
	double y;
	double z;
}				t_vec3d;

double			kt_dotproduct2d(t_vec2d v0, t_vec2d v1);
double			kt_dotproduct3d(t_vec3d v0, t_vec3d v1);
double			kt_crossproduct(t_vec3d v0, t_vec3d v1);

#endif
