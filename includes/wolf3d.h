/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:50 by gwood             #+#    #+#             */
/*   Updated: 2018/10/17 15:27:55 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <X11/Xlib.h>
# include "libft.h"

typedef struct	s_data
{
	Display *dpy;
	int		scr;
	int		black_color;
	int		white_color;
	Window	win;
	GC		gc;
}				t_data;

#endif
