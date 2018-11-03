/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3d_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 12:13:27 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 14:58:23 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

void			kt_tr3d_translate(double m[4][4], double tx, double ty, double tz)
{
	double		tmat[4][4];

	kt_mat3d_identity(tmat);
	tmat[3][0] = tx;
	tmat[3][1] = ty;
	tmat[3][2] = tz;
	kt_mat3d_mult(m, tmat, m);
}

void			kt_tr3d_scale(double m[4][4], double sx, double sy, double sz)
{
	double		smat[4][4];

	kt_mat3d_bzero(smat);
	smat[0][0] = sx;
	smat[1][1] = sy;
	smat[2][2] = sz;
	smat[3][3] = 1;
	kt_mat3d_mult(m, smat, m);
}

void			kt_tr3d_rotate(double m[4][4], double ax, double ay, double az)
{
	double		xmat[4][4];
	double		ymat[4][4];
	double		zmat[4][4];
	double		mat1[4][4];
	double		mat2[4][4];

	ax *= 0.01745329252;
	ay *= 0.01745329252;
	az *= 0.01745329252;
	kt_mat3d_identity(xmat);
	kt_mat3d_identity(ymat);
	kt_mat3d_identity(zmat);
	xmat[1][1] = cos(ax);
	xmat[1][2] = sin(ax);
	xmat[2][1] = -sin(ax);
	xmat[2][2] = cos(ax);
	ymat[0][0] = cos(ay);
	ymat[0][2] = -sin(ay);
	ymat[2][0] = sin(ay);
	ymat[2][2] = cos(ay);
	zmat[0][0] = cos(az);
	zmat[0][1] = sin(az);
	zmat[1][0] = -sin(az);
	zmat[1][1] = cos(az);
	kt_mat3d_mult(m, ymat, mat1);
	kt_mat3d_mult(mat1, xmat, mat2);
	kt_mat3d_mult(mat2, zmat, m);
}
