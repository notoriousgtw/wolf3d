/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:10:37 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 14:34:25 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"

void	kt_bzero_mat2d(double m[3][3]);
void	kt_identity_mat2d(double m[3][3]);
void	kt_mat2d_mult(double m0[3][3], double m1[3][3], double m2[3][3]);
void	kt_mat2d_copy(double m0[3][3], double m1[3][3]);

void	kt_tr2d_translate(double m[3][3], double tx, double ty);
void	kt_tr2d_scale(double m[3][3], double sx, double sy);
void	kt_tr2d_rotate(double m[3][3], double a);

#endif
