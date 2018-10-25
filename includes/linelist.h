/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:58:36 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 13:43:18 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINELIST_H
# define LINELIST_H

# include "vertlist.h"

typedef int		t_line[3];

typedef struct	s_linelist
{
	t_vertlist	*verts;
	t_line		*indices;
	int			arr_len;
	int			list_size;
}				t_linelist;

void			kt_line_color(t_line t, int color);
void			kt_line_print_data(const t_line t);

void			kt_linelist_init(t_linelist *l, t_vertlist *v);
void			kt_linelist_draw(t_linelist *l, t_xvars *x);
void			kt_linelist_color(t_linelist *l, int color);
void			kt_linelist_print_data(const t_linelist *l);
void			kt_linelist_add(t_linelist *l, int p0, int p1);
void			kt_linelist_insert(t_linelist *l, int p0, int p1, int index);

#endif
