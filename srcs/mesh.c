/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:49:35 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 21:46:51 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"
#include <stdio.h>

void			kt_mesh_print_data(const t_meshdata *m)
{
	kt_indexlist_print_data(&m->indices);
	kt_vertlist_print_data(&m->indices);
}
