/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 01:44:43 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trilist.h"
#include <stdio.h>

void			kt_trilist_init(t_trilist *l, t_vertlist *v)
{
	l->verts = v;
}

void			kt_trilist_print_data(const t_trilist *l)
{
	kt_vertlist_print_data(l->verts);
	kt_indexlist_print_data();
}
