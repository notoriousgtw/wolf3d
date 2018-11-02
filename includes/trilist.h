/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:58:36 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 04:46:27 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRILIST_H
# define TRILIST_H

# include "vertlist.h"
# include "indexlist.h"

typedef struct	s_trilist
{
	t_vertlist	*verts;
	t_indexlist	*indices;
}				t_trilist;

void			kt_trilist_init(t_trilist *l, t_vertlist *v);
void			kt_trilist_print_data(const t_trilist *l);
void			kt_trilist_add(t_trilist *l, size_t p0, size_t p1, size_t p2);
void			kt_trilist_insert(t_trilist *l, size_t p0, size_t p1, size_t p2, ...);

#endif
