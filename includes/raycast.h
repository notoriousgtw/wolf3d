/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:38:02 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 13:38:02 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "mesh.h"

typedef struct	s_map
{
	int			h;
	int			w;
	int			**cell;
}				t_map;

typedef struct	s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		plane;
	double		rot_speed;
	double		move_speed;
}				t_player;

typedef struct	s_time
{
	int			cur_sec;
	int			past;
	double		old;
	double		cur;
	double		frame;
}				t_time;

typedef struct	s_floorcast
{
	t_vec2d		wall;
	t_vec2d		pos;
	int			tex_x;
	int			tex_y;
	int			texture;
	double		weight;
}				t_floorcast;

typedef struct	s_raycast
{
	int			map_x;
	int			map_y;
	t_vec2d		camera;
	t_vec2d		ray_pos;
	t_vec2d		ray_dir;
	t_vec2d		side_dist;
	t_vec2d		delta_dist;
	double		perp_wall_dist;
	double		wall_x;
	int			hit;
	int			step_x;
	int			step_y;
	int			tex_x;
	int			tex_y;
	int			side;
	int			tile;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_raycast;

void			bb_step_and_side_dist(t_raycast *cast);
void			bb_delta_dist(t_raycast *cast);

#endif
