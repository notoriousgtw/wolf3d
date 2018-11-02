/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:13:00 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 04:52:44 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EFFECT_H
# define EFFECT_H

# include "vertex.h"
# include "primitive.h"

typedef struct		s_vs
{
	void	(*fnc)(struct s_vs *vs, t_vert *vert);
	double	mat[4][4];
	void	*data;
}					t_vs;

typedef struct		s_gs
{
	void	(*fnc)(struct s_gs *gs, t_prim *prim, size_t index, t_vert *verts);
	void	*data;
}					t_gs;

typedef struct		s_ps
{
	int		(*fnc)(struct s_ps *ps, const t_vert *attr);
	void	*data;
}					t_ps;

typedef struct		s_effect
{
	t_vs	vs;
	t_gs	gs;
	t_ps	ps;
	void	*data;
}					t_effect;

typedef void		(*t_vs_fnc)(t_vs *vs, t_vert *vert);
typedef void		(*t_gs_fnc)(t_gs *gs, t_prim *prim, size_t index,
								t_vert *verts);
typedef int			(*t_ps_fnc)(t_ps *ps, const t_vert *attr);

void				kt_gs_default_init(t_gs *gs);
void				kt_gs_default_fnc(t_gs *gs, t_prim *prim, size_t index,
									  t_vert *verts);

void				kt_vs_color_init(t_vs *vs, double mat[4][4], int color);
void				kt_vs_color_fnc(t_vs *vs, t_vert *vert);
void				kt_ps_color_init(t_ps *ps);
int					kt_ps_color_fnc(t_ps *ps, const t_vert *attr);
#endif
