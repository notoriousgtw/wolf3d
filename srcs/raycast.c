/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:51:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/11/05 15:51:30 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/raycast.h"

void			bb_delta_dist(t_raycast *rc)
{
	t_vec2d		r_dir_sq;

	r_dir_sq.x = (rc->r_dir.x * rc->r_dir.x);
	r_dir_sq.y = (rc->r_dir.y * rc->r_dir.y);
	rc->delta_dist.x = sqrt(1 + (r_dir_sq.y) / (r_dir_sq.x));
	rc->delta_dist.y = sqrt(1 + (r_dir_sq.x) / (r_dir_sq.y));
}

void			bb_step_and_side_dist(t_raycast *rc)
{
	if (rc->r_dir.x < 0)
	{
		rc->step_x = -1;
		rc->side_dist.x = (rc->r_pos.x - rc->map_x)
								* rc->delta_dist.x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist.x = (rc->map_x + 1.0 - rc->r_pos.x)
								* rc->delta_dist.x;
	}
	if (rc->r_dir.y < 0)
	{
		rc->step_y = -1;
		rc->side_dist.y = (rc->r_pos.y - rc->map_y)
								* rc->delta_dist.y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist.y = (rc->map_y + 1.0 - rc->r_pos.y)
								* rc->delta_dist.y;
	}
}

void			bb_raycast_init(t_data *d, t_raycast *rc, int x)
{

	rc->camera.x = 2 * x / (double)d->x.width - 1;
	rc->r_pos.x = d->player.pos.x;
	rc->r_pos.y = d->player.pos.y;
	rc->r_dir.x = d->player.dir.x + d->player.plane.x * rc->camera.x;
	rc->r_dir.y = d->player.dir.y + d->player.plane.y * rc->camera.x;
	rc->map_x = (int)d->player.pos.x;
	rc->map_y = (int)d->player.pos.y;
	rc->tile = TILE_AT(rc->map_x, rc->map_y);
	rc->hit = 0;
}

void			bb_raycast_dda(t_data *d, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->side_dist.x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		rc->tile = TILE_AT(rc->map_x, rc->map_y);
		if (rc->tile > 0)
			rc->hit = 1;
	}
}
