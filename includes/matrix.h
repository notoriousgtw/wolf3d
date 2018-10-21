/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:10:37 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 00:22:18 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"
# include <math.h>

void	kt_mat2d_bzero(double m[3][3]);
void	kt_mat2d_identity(double m[3][3]);
void	kt_mat2d_mult(double m0[3][3], double m1[3][3], double m2[3][3]);
void	kt_mat2d_copy(double m0[3][3], double m1[3][3]);

void	kt_tr2d_translate(double m[3][3], double tx, double ty);
void	kt_tr2d_scale(double m[3][3], double sx, double sy);
void	kt_tr2d_rotate(double m[3][3], double a);

void	kt_mat3d_bzero(double m[4][4]);
void	kt_mat3d_identity(double m[4][4]);
void	kt_mat3d_mult(double m0[4][4], double m1[4][4], double m2[4][4]);
void	kt_mat3d_copy(double m0[4][4], double m1[4][4]);

void	kt_tr3d_translate(double m[4][4], double tx, double ty, double tz);
void	kt_tr3d_scale(double m[4][4], double sx, double sy, double sz);
void	kt_tr3d_rotate(double m[4][4], double ax, double ay, double az);

#endif
