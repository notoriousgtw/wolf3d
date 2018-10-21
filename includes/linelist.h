/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linelist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:58:36 by gwood             #+#    #+#             */
/*   Updated: 2018/10/21 12:22:28 by gwood            ###   ########.fr       */
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

void			kt_linelist_init(t_linelist *l, t_vertlist *v);
void			kt_linelist_draw(t_linelist *l, t_xvars *x);
void			kt_linelist_app(t_linelist *l, t_line line);
void			kt_linelist_add(t_linelist *l, t_line line, int index);

#endif
