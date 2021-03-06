/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 11:47:43 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 15:48:04 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/matrix.h"

void			kt_mat2d_bzero(double m[3][3])
{
	ft_bzero(m[0], sizeof(double) * 3);
	ft_bzero(m[1], sizeof(double) * 3);
	ft_bzero(m[2], sizeof(double) * 3);
}

void			kt_mat2d_identity(double m[3][3])
{
	kt_mat2d_bzero(m);
	m[0][0] = 1;
	m[1][1] = 1;
	m[2][2] = 1;
}

void			kt_mat2d_mult(double m0[3][3], double m1[3][3], double m2[3][3])
{
	int i;
	int j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m2[i][j] = m0[i][0] * m1[0][j] +
					   m0[i][1] * m1[1][j] +
					   m0[i][2] * m1[2][j];
	}
}

void			kt_mat2d_copy(double m0[3][3], double m1[3][3])
{
	int i;
	int j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m1[i][j] = m0[i][j];
	}
}
