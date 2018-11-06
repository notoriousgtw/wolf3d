/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:51:49 by gwood             #+#    #+#             */
/*   Updated: 2018/11/05 22:28:56 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"

void			kt_cube_init_plain_quads(double size, t_meshdata *m)
{
	size /= 2;
	kt_vertlist_init(&m->verts);
	kt_vertlist_add(&m->verts, -size, -size, size);
	kt_vertlist_add(&m->verts, size, -size, size);
	kt_vertlist_add(&m->verts, size, size, size);
	kt_vertlist_add(&m->verts, -size, size, size);
	kt_vertlist_add(&m->verts, -size, -size, -size);
	kt_vertlist_add(&m->verts, size, -size, -size);
	kt_vertlist_add(&m->verts, size, size, -size);
	kt_vertlist_add(&m->verts, -size, size, -size);
	kt_indexlist_init(&m->indices, 4);
	kt_indexlist_add(&m->indices, 0, 2, 1, 3);
	kt_indexlist_add(&m->indices, 1, 3, 5, 7);
	kt_indexlist_add(&m->indices, 2, 6, 3, 2);
	kt_indexlist_add(&m->indices, 4, 0, 3, 7);
	kt_indexlist_add(&m->indices, 3, 7, 6, 2);
	kt_indexlist_add(&m->indices, 4, 0, 1, 5);
}

void			kt_cube_init_plain_tris(double size, t_meshdata *m)
{
	size /= 2;
	kt_vertlist_init(&m->verts);
	kt_vertlist_add(&m->verts, -size, -size, -size);
	kt_vertlist_add(&m->verts, size, -size, -size);
	kt_vertlist_add(&m->verts, -size, size, -size);
	kt_vertlist_add(&m->verts, size, size, -size);
	kt_vertlist_add(&m->verts, -size, -size, size);
	kt_vertlist_add(&m->verts, size, -size, size);
	kt_vertlist_add(&m->verts, -size, size, size);
	kt_vertlist_add(&m->verts, size, size, size);
	kt_indexlist_init(&m->indices, 3);
	kt_indexlist_add(&m->indices, 0, 2, 1);
	kt_indexlist_add(&m->indices, 2, 3, 1);
	kt_indexlist_add(&m->indices, 1, 3, 5);
	kt_indexlist_add(&m->indices, 3, 7, 5);
	kt_indexlist_add(&m->indices, 2, 6, 3);
	kt_indexlist_add(&m->indices, 3, 6, 7);
	kt_indexlist_add(&m->indices, 4, 5, 7);
	kt_indexlist_add(&m->indices, 4, 7, 6);
	kt_indexlist_add(&m->indices, 0, 4, 2);
	kt_indexlist_add(&m->indices, 2, 4, 6);
	kt_indexlist_add(&m->indices, 0, 1, 4);
	kt_indexlist_add(&m->indices, 1, 5, 4);
}
