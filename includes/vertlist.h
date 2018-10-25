/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:20:01 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 12:14:12 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTLIST_H
# define VERTLIST_H

#include "libft.h"
#include "vector.h"

typedef struct	s_vertlist
{
	t_vec3d			*data;
	int				arr_len;
	int				list_size;
}				t_vertlist;

void			kt_vertlist_init(t_vertlist *l);
void			kt_vertlist_transform(t_vertlist *l, double m[4][4]);
void			kt_vertlist_screenify(t_vertlist *l, t_xvars *x);
void			kt_vertlist_print_data(const t_vertlist *l);
void			kt_vertlist_app(t_vertlist *l, t_vec3d v);
void			kt_vertlist_add(t_vertlist *l, t_vec3d v, int index);

#endif
