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

#include "../includes/graphics.h"
#include "../includes/color.h"
#include <stdio.h>

void			bb_line_color(t_line t, int color)
{
	t[2] = color;
}

void			kt_line_print_data(const t_line t)
{
	printf("v%d, v%d color: %d", t[0], t[1], t[2]);
}
