/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:26:47 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 22:39:13 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "vertlist.h"

void	kt_vertlist_init(t_vertlist *l)
{
	if (!(l->data = ft_memalloc(sizeof(t_vec3d) * 5)))
		ft_error_unknown("wolf3d: ");
	l->arr_len = 5;
	l->list_size = 0;
}

void	kt_vertlist_transform(t_vertlist *l, double m[4][4])
{
	int i;

	i = -1;
	while (++i < l->list_size)
		kt_vec3d_transform(l->data[i], m, &(l->data[i]));
}

void	kt_vertlist_screenify(t_vertlist *l, t_xvars *x)
{
	int				i;

	i = -1;
	while (++i < l->list_size)
		kt_vec3d_screenify(x, &(l->data[i]));
}
