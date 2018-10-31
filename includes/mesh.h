/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:43:44 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 21:46:26 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "graphics.h"

typedef struct s_vert	t_vert;

typedef struct			s_meshdata
{
	t_vertlist	verts;
	t_indexlist indices;
}						t_meshdata;

void	kt_mesh_print_data(const t_meshdata *m)

#endif
