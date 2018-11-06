/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:50 by gwood             #+#    #+#             */
/*   Updated: 2018/11/01 05:04:57 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <math.h>
# include "graphics.h"
# include "matrix.h"
# include "keys.h"
# include "color.h"
# include "pipeline.h"
# include "raycast.h"

# define TILE_AT(x, y) d->map.cell[(int)(x)][(int)(y)]

typedef struct	s_data
{
	t_map		map;
	t_player	player;
	t_time		t;
	int			mouse_x;
	int			mouse_y;
	int			tex_h;
	int			tex_w;
	double		*z_buf;
	t_keys		pressed;
	t_xvars		x;
}				t_data;

void			bb_start(t_data *d);
void			bb_close(t_data *d);
void			bb_restart(t_data *d);
void			bb_init_pressed(t_data *d);
void			bb_init_colors(t_data *data);
void			bb_redraw(t_data *d, int solid);
void			bb_draw_rect(t_data *d);
void			bb_menu(t_data *d);
t_map			bb_parse_map(const char *file);
void			bb_free_map(t_map *map);

void			kt_create_window(t_data *d);
void			kt_draw_cube(t_data *d);

#endif
