/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:40:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 22:06:14 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"

static void				bb_rect_init_v(t_cube *c, double size)
{
	c->verts[0].pos.x = -size;
	c->verts[0].pos.y = -size;
	c->verts[0].pos.z = -size;
	c->verts[1].pos.x = size;
	c->verts[1].pos.y = -size;
	c->verts[1].pos.z = -size;
	c->verts[2].pos.x = -size;
	c->verts[2].pos.y = size;
	c->verts[2].pos.z = -size;
	c->verts[3].pos.x = size;
	c->verts[3].pos.y = size;
	c->verts[3].pos.z = -size;
	c->verts[4].pos.x = -size;
	c->verts[4].pos.y = -size;
	c->verts[4].pos.z = size;
	c->verts[5].pos.x = size;
	c->verts[5].pos.y = -size;
	c->verts[5].pos.z = size;
	c->verts[6].pos.x = -size;
	c->verts[6].pos.y = size;
	c->verts[6].pos.z = size;
	c->verts[7].pos.x = size;
	c->verts[7].pos.y = size;
	c->verts[7].pos.z = size;
}

static void				bb_rect_init_line(t_cube *c)
{
	const int			white = c->data.x->white_color;
	// const int		color = c->data.x->c->color[2];
	const t_line		lines[12] =
	{
		{0, 1, white}, {1, 3, white}, {3, 2, white}, {2, 0, white},
		{0, 4, white}, {1, 5, white}, {3, 7, white}, {2, 6, white},
		{4, 5, white}, {5, 7, white}, {7, 6, white}, {6, 4, white}
	};
	ft_memcpy(c->lines, &lines, sizeof(t_line) * 12);
}

static void 			bb_rect_init_tri(t_cube *c)
{
	const int			white = c->data.x->white_color;
	const t_indexlist	tris[12] =
	{
		{0, 2, 1, white}, {2, 3, 1, white},
		{1, 3, 5, white}, {3, 7, 5, white},
		{2, 6, 3, white}, {3, 6, 7, white},
		{4, 5, 7, white}, {4, 7, 6, white},
		{0, 4, 2, white}, {2, 4, 6, white},
		{0, 1, 4, white}, {1, 5, 4, white}
	};
	ft_memcpy(c->tris, &tris, sizeof(t_indexlist) * 12);
}

void					bb_rect_init(t_cube *c, t_xvars *x, double size)
{
	c->data.x = x;
	c->data.n_verts = 8;
	c->data.n_lines = 12;
	c->data.n_tris = 12;
	c->data.verts = c->verts;
	c->data.lines = c->lines;
	c->data.tris = c->tris;
	c->data.cull_flags = c->cull_flags;
	bb_rect_init_v(c, size / 2);
	bb_rect_init_line(c);
	bb_rect_init_tri(c);
}
