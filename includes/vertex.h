/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:27:25 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 14:47:54 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "graphics.h"

typedef void	(*t_vert_data_interpolate)(void *d0, void* d1, void *d2);
typedef void	(*t_vert_data_print)(void *data);
typedef void	(*t_vert_data_free)(void *data);
typedef struct	s_vert
{
	t_vec3d					pos;
	void					*data;
	size_t					data_size;
	t_vert_data_interpolate	interpolate_data;
	t_vert_data_print		print_data;
	t_vert_data_free		free_data;
}				t_vert;

void			kt_vert_init(t_vert *v, double x, double y, double z);
void			kt_vert_dup(const t_vert *v0, t_vert *v1);
void			kt_vert_bind_data(t_vert *v, void *data, size_t data_size);
void			kt_vert_bind_data_funcs(t_vert *v,
										t_vert_data_interpolate interpolate,
										t_vert_data_print print,
										t_vert_data_free free);
void			kt_vert_print(const t_vert *v);
t_bool			kt_vert_comp_type(const t_vert *v0, const t_vert *v1);

#endif
