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

void			bb_delta_dist(t_raycast *cast)
{
	t_vec2d		ray_dir_sq;

	ray_dir_sq.x = cast->ray_dir.x * cast->ray_dir.x;
	ray_dir_sq.y = cast->ray_dir.y * cast->ray_dir.y;
	cast->delta_dist.x = sqrt(1 + (ray_dir_sq.y) / (ray_dir_sq.x));
	cast->delta_dist.y = sqrt(1 + (ray_dir_sq.x) / (ray_dir_sq.y));
}

void			bb_step_and_side_dist(t_raycast *cast)
{
	if (cast->ray_dir.x < 0)
	{
		cast->step_x = -1;
		cast->side_dist.x = (cast->ray_pos.x - cast->map_x)
								* cast->delta_dist.x;
	}
	else
	{
		cast->step_x = 1;
		cast->side_dist.x = (cast->map_x + 1.0 - cast->ray_pos.x)
								* cast->delta_dist.x;
	}
	if (cast->ray_dir.y < 0)
	{
		cast->step_y = -1;
		cast->side_dist.y = (cast->ray_pos.y - cast->map_y)
								* cast->delta_dist.y;
	}
	else
	{
		cast->step_y = 1;
		cast->side_dist.y = (cast->map_y + 1.0 - cast->ray_pos.y)
								* cast->delta_dist.y;
	}
}

void			bb_raycast_init(t_data *d, t_raycast *cast, int x)
{

	cast->camera.x = 2 * x / (double)d->x.width - 1;
	cast->ray_pos.x = d->player.pos.x;
	cast->ray_pos.y = d->player.pos.y;
	cast->ray_dir.x = d->player.dir.x + d->player.plane.x * cast->camera.x;
	cast->ray_dir.y = d->player.dir.y + d->player.plane.y * cast->camera.x;
	cast->map_x = (int)d->player.pos.x;
	cast->map_y = (int)d->player.pos.y;
	cast->tile = TILE_AT(cast->map_x, cast->map_y);
	cast->hit = 0;
}

void			bb_raycast_dda(t_data *d, t_raycast *cast)
{
	while (cast->hit == 0)
	{
		if (cast->side_dist.x < cast->side_dist.y)
		{
			cast->side_dist.x += cast->side_dist.x;
			cast->map_x += cast->step_x;
			cast->side = 0;
		}
		else
		{
			cast->side_dist.y += cast->delta_dist.y;
			cast->map_y += cast->step_y;
			cast->side = 1;
		}
		cast->tile = TILE_AT(cast->map_x, cast->map_y);
		if (cast->tile > 0)
			cast->hit = 1;
	}
}
