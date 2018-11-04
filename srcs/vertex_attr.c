/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 00:56:42 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 21:21:23 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vertex.h"

void				kt_vert_bind_data(t_vert *v, void *data, size_t data_size)
{
	v->attr = data;
	v->attr_size= data_size;
}

void				kt_vert_unbind_data(t_vert *v)
{
	if (v->free_attr != NULL)
		v->free_attr(v->attr);
	v->attr = NULL;
	v->attr_size = 0;
	v->add_attr = NULL;
	v->sub_attr = NULL;
	v->mult_attr = NULL;
	v->div_attr = NULL;
	v->print_attr = NULL;
	v->free_attr = NULL;
}
