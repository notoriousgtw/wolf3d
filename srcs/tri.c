/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:07:10 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 21:01:58 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "trilist.h"
#include <stdio.h>

void	bb_tri_color(t_tri t, int color)
{
	t_color		c;

	bb_init_color_table(&c, color);
	t[3] = c.color[3];
}

void	kt_tri_print_data(const t_tri t)
{
	printf("v%d, v%d, v%d color: %d", t[0], t[1], t[2], t[3]);
}
