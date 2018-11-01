/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:13:00 by gwood             #+#    #+#             */
/*   Updated: 2018/10/30 20:51:48 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EFFECT_H
# define EFFECT_H

# include "graphics.h"

typedef void				(*t_vertex_shader_fnc)(t_vert *v);
typedef void				(*t_geometry_shader_fnc)(t_tri *t, t_vert *v0, t_vert *v1, t_vert *v2, ...);
typedef void				(*t_pixel_shader_fnc)(void *d);

typedef struct				s_effect
{
	t_vertex_shader_fnc		vs;
	t_geometry_shader_fnc	gs;
	t_pixel_shader_fnc		ps;
}							t_effect;

typedef struct				s_vs_default
{

}							t_vs_default;

void						kt_vs_default(t_vert *v);
void						kt_gs_default(t_tri *t, t_vert *v0, t_vert *v1,
											t_vert *v2, ...);
void						kt_ps_default(void *d);
#endif
