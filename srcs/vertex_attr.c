/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 00:56:42 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 01:01:22 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vertex.h"

void				kt_vert_bind_data(t_vert *v, void *data, size_t data_size)
{
	v->attr = data;
	v->attr_size= data_size;
}

void				kt_vert_bind_data_funcs(t_vert *v,
								t_vert_attr_interpolate interpolate,
								t_vert_attr_print print,
								t_vert_attr_free free_attr)
{
	v->interpolate_attr = interpolate;
	v->print_attr = print;
	v->free_attr = free_attr;
}

void				kt_vert_unbind_data(t_vert *v)
{
	if (v->free_attr != NULL)
		v->free_attr(v->attr);
	v->attr = NULL;
	v->attr_size = 0;
	v->interpolate_attr = NULL;
	v->print_attr = NULL;
	v->free_attr = NULL;
}
