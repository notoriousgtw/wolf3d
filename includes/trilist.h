/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:58:36 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 17:19:50 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRILIST_H
# define TRILIST_H

# include "vertlist.h"
# include "color.h"

typedef int		t_tri[4];

typedef struct	s_trilist
{
	t_vertlist	*verts;
	t_tri		*indices;
	t_bool		*cull_flags;
	int			arr_len;
	int			list_size;
	t_color		*c;
}				t_trilist;

void			bb_tri_color(t_tri t, int color);
void			kt_tri_print_data(const t_tri t);

void			kt_trilist_init(t_trilist *l, t_vertlist *v);
void			kt_trilist_draw(t_trilist *l, t_xvars *x);
void			bb_trilist_color(t_trilist *l, int color);
void			kt_trilist_print_data(const t_trilist *l);
void			kt_trilist_add(t_trilist *l, int p0, int p1, int p2);
void			kt_trilist_insert(t_trilist *l, int p0, int p1, int p2, ...);

#endif
