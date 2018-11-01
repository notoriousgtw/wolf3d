/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_shaders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:16:09 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:53:42 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "effect.h"

void	kt_vs_default_init(t_vs *vs, t_vs_fnc *fnc, double mat[4][4])
{
	vs->fnc = fnc;
	ft_memcpy(vs->mat, mat, sizeof(double) * 4);
}
