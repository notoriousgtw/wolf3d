/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:13:00 by gwood             #+#    #+#             */
/*   Updated: 2018/10/31 22:10:03 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EFFECT_H
# define EFFECT_H

# include "graphics.h"

typedef struct	s_vs
{
	t_vs_fnc	fnc;
	double		mat[4][4];
	void		*data;
}				t_vs;

typedef struct	s_gs
{
	t_gs_fnc	fnc;
	void		*data;
}				t_gs;

typedef struct	s_ps
{
	t_ps_fnc	fnc;
	void		*data;
}				t_ps;
typedef struct	s_effect
{
	t_vs	vs;
	t_gs	gs;
	t_ps	ps;
}				t_effect;

typedef void	(*t_vs_fnc)(t_vs *vs, t_vert *vert);
typedef void	(*t_gs_fnc)(t_gs *gs, t_prim *prim, size_t index, ...);
typedef void	(*t_ps_fnc)(void *d);

void			kt_vs_default_init(t_vs *vs, t_vs_fnc *fnc, double mat[4][4]);
void			kt_vs_default_fnc(t_vs *vs, t_vert *v);
void			kt_gs_default_fnc(t_gs *gs, t_prim *prim, size_t index, ...);
void			kt_ps_default_fnc(void *d);
#endif
