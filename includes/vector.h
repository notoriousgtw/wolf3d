/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 14:46:43 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 05:06:41 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../libft/includes/libft.h"
# include "../includes/graphics.h"

typedef struct	s_vec2d_i
{
	int			x;
	int			y;
}				t_vec2d_i;

typedef struct	s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct	s_vec3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

void			kt_vec2d_swap(t_vec2d *v0, t_vec2d *v1);
double			kt_vec2d_dotproduct(t_vec2d v0, t_vec2d v1);
void			kt_vec2d_interpolate(t_vec2d v0, t_vec2d v1, double alpha, t_vec2d *v2);
void			kt_vec2d_transform(t_vec2d v0, double m[3][3], t_vec2d *v1);
void			kt_vec2d_print_data(t_vec2d v);
void			kt_vec2d_ftoi(t_vec2d v0, t_vec2d_i *v1, int r);

void			kt_vec3d_swap(t_vec3d *v0, t_vec3d *v1);
double			kt_vec3d_dotproduct(t_vec3d v0, t_vec3d v1);
void			kt_vec3d_crossproduct(t_vec3d v0, t_vec3d v1, t_vec3d *v2);
void			kt_vec3d_interpolate(t_vec3d v0, t_vec3d v1, double alpha, t_vec3d *v2);
void			kt_vec3d_transform(t_vec3d v0, double m[4][4], t_vec3d *v1);
void			kt_vec3d_screenify(t_xvars *x, t_vec3d v0, t_vec3d *v1);
void			kt_vec3d_print_data(t_vec3d v);

double			bb_vec3d_len(t_vec3d *v);
double			bb_vec2d_len(t_vec2d *v);

#endif
