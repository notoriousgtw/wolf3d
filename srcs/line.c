/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:16:22 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 20:57:29 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "linelist.h"
#include "color.h"
#include <stdio.h>

void	bb_line_color(t_line t, int color)
{
	t_color		c;

	bb_init_color_table(&c, color);
	t[2] = c.color[2];
}

void	kt_line_print_data(const t_line t)
{
	printf("v%d, v%d color: %d", t[0], t[1], t[2]);
}
