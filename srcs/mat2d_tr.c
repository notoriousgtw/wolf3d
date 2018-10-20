/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2d_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 12:13:27 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 15:48:04 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

void	kt_tr2d_translate(double m[3][3], double tx, double ty)
{
	double	tmat[3][3];

	kt_mat2d_identity(tmat);
	tmat[2][0] = tx;
	tmat[2][1] = ty;
	kt_mat2d_mult(m, tmat, m);
}

void	kt_tr2d_scale(double m[3][3], double sx, double sy)
{
	double	smat[3][3];

	kt_mat2d_bzero(smat);
	smat[0][0] = sx;
	smat[1][1] = sy;
	smat[2][2] = 1;
	kt_mat2d_mult(m, smat, m);
}

void	kt_tr2d_rotate(double m[3][3], double a)
{
	double	rmat[3][3];

	kt_mat2d_identity(rmat);
	rmat[0][0] = cos(a);
	rmat[0][1] = sin(a);
	rmat[1][0] = -sin(a);
	rmat[1][1] = cos(a);
	kt_mat2d_mult(m, rmat, m);
}
