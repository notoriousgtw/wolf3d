/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:20:01 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 05:13:00 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTLIST_H
# define VERTLIST_H

# include "vertex.h"

typedef struct	s_vertlist
{
	t_vert		*data;
	int			arr_len;
	int			list_size;
}				t_vertlist;

void			kt_vertlist_init(t_vertlist *l);
void			kt_vertlist_dup(const t_vertlist *l0, t_vertlist *l1);
void			kt_vertlist_print(const t_vertlist *l);
void			kt_vertlist_add(t_vertlist *l, double x, double y, double z);
void			kt_vertlist_insert(t_vertlist *l, size_t index, ...);
void			kt_vertlist_free(t_vertlist *l);

#endif
