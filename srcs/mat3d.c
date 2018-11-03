/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:47:43 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 15:48:31 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

void			kt_mat3d_bzero(double m[4][4])
{
	ft_bzero(m[0], sizeof(double) * 4);
	ft_bzero(m[1], sizeof(double) * 4);
	ft_bzero(m[2], sizeof(double) * 4);
	ft_bzero(m[3], sizeof(double) * 4);
}

void			kt_mat3d_identity(double m[4][4])
{
	kt_mat3d_bzero(m);
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
	m[3][3] = 1;
}

void			kt_mat3d_mult(double m0[4][4], double m1[4][4], double m2[4][4])
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m2[i][j] = m0[i][0] * m1[0][j] +
					   m0[i][1] * m1[1][j] +
					   m0[i][2] * m1[2][j] +
					   m0[i][3] * m1[3][j];
	}
}

void			kt_mat3d_copy(double m0[4][4], double m1[4][4])
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m1[i][j] = m0[i][j];
	}
}
