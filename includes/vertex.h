/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:27:25 by gwood             #+#    #+#             */
/*   Updated: 2018/11/03 19:29:22 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

#include "vector.h"

typedef void		(*vert_attr_vmath)(const void *a0, const void *a1,
											void *a2);
typedef void		(*vert_attr_dmath)(const void *a0, double x,
											void *a1);
typedef void		(*vert_attr_print)(void *data);
typedef void		(*vert_attr_free)(void *data);

typedef struct		s_vert
{
	t_vec3d			pos;
	void			*attr;
	size_t			attr_size;
	vert_attr_vmath	add_attr;
	vert_attr_vmath	sub_attr;
	vert_attr_dmath	mult_attr;
	vert_attr_dmath	div_attr;
	vert_attr_print	print_attr;
	vert_attr_free	free_attr;
}					t_vert;

void				kt_vert_init(t_vert *v, double x, double y, double z);
void				kt_vert_dup(const t_vert *v0, t_vert *v1);
void				kt_vert_bind_data(t_vert *v, void *data, size_t data_size);
void				kt_vert_transform(t_vert *v0, double mat[4][4]);
void				kt_vert_add(const t_vert *v0, const t_vert *v1, t_vert *v2);
void				kt_vert_sub(const t_vert *v0, const t_vert *v1, t_vert *v2);
void				kt_vert_mult(const t_vert *v0, double x, t_vert *v1);
void				kt_vert_div(const t_vert *v0, double x, t_vert *v1);
void				kt_vert_print(const t_vert *v);
t_bool				kt_vert_comp_type(const t_vert *v0, const t_vert *v1);

#endif
