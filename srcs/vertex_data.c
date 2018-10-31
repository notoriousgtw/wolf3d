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

#include "vertex.h"

void	kt_vert_bind_data(t_vert *v, void *data, size_t data_size)
{
	v->data = data;
	v->data_size = data_size;
}

void	kt_vert_bind_data_funcs(t_vert *v,
								t_vert_data_interpolate interpolate,
								t_vert_data_print print,
								t_vert_data_free free_data)
{
	v->interpolate_data = interpolate;
	v->print_data = print;
	v->free_data = free_data;
}

void	kt_vert_unbind_data(t_vert *v)
{
	if (v->free_data != NULL)
		v->free_data(v->data);
	v->data = NULL;
	v->data_size = 0;
	v->interpolate_data = NULL;
	v->print_data = NULL;
	v->free_data = NULL;
}
