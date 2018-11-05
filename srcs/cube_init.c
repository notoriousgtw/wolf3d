/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:51:49 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 22:34:33 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"

void			kt_cube_init_plain(double size, t_meshdata *m)
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
	kt_indexlist_add(&m->indices, 0, 3, 2, 1);
	kt_indexlist_add(&m->indices, 5, 6, 7, 4);
	kt_indexlist_add(&m->indices, 1, 2, 6, 5);
	kt_indexlist_add(&m->indices, 4, 0, 3, 7);
	kt_indexlist_add(&m->indices, 3, 7, 6, 2);
	kt_indexlist_add(&m->indices, 4, 0, 1, 5);
}
