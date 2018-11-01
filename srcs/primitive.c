/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:40:23 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:27:30 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primitive.h"
#include <stdarg.h>

void	kt_prim_init(t_prim *prim, ssize_t vert_count, ...)
{
	int		i;
	va_list ap;

	if (prim->verts)
		free(prim->verts);
	if (vert_count < 0)
	{
		prim->verts = NULL;
		prim->vert_count = -vert_count;
		return ;
	}
	else if (vert_count == 0)
	{
		prim->verts = NULL;
		prim->vert_count = 0;
		return ;
	}
	else if (vert_count < 2 || vert_count > 4)
		return ;
	if (!(prim->verts = (t_vert *) ft_memalloc(sizeof(t_vert) * vert_count)))
		return ;
	prim->vert_count = vert_count;
	i = -1;
	va_start(ap, vert_count);
	while (++i < vert_count)
		kt_vert_dup(va_arg(ap, t_vert *), &(prim->verts[i]));
	va_end(ap);
}

void	kt_prim_free(t_prim *prim)
{
	int	i;

	i = -1;
	while (++i < prim->vert_count)
		if (prim->verts[i].free_data != NULL)
			prim->verts[i].free_data(prim->verts[i].data);
	free(prim->verts);
}
