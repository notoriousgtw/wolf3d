/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 21:58:36 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 04:50:39 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEXLIST_H
# define INDEXLIST_H

# include "../libft/includes/libft.h"

typedef struct	s_indexlist
{
	size_t		*data;
	size_t		index_count;
	int			arr_len;
	int			list_size;
}				t_indexlist;

void			kt_indexlist_init(t_indexlist *l, size_t index_count);
void			kt_indexlist_dup(const t_indexlist *l0, t_indexlist *l1);
void			kt_indexlist_print_data(const t_indexlist *l);
void			kt_indexlist_add(t_indexlist *l, ...);
void			kt_indexlist_insert(t_indexlist *l, size_t index, ...);
void			kt_indexlist_free(t_indexlist *l);

#endif
