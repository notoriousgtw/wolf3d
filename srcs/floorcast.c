/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:33:31 by jfleisch          #+#    #+#             */
/*   Updated: 2018/11/06 17:33:31 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		floorcast_prep(t_data *d, t_raycast *rc, t_vec2d *floor_wall)
{
	if (rc->side == 0 && rc->r_dir.x > 0)
	{
		floor_wall->x = rc->map_x;
		floor_wall->y = rc->map_y + rc->wall_x;
	}
	else if (rc->side == 0 && rc->r_dir.x < 0)
	{
		floor_wall->x = rc->map_x + 1.0;
		floor_wall->y = rc->map_y + rc->wall_x;
	}
	else if (rc->side == 1 && rc->r_dir.x > 0)
	{
		floor_wall->x = rc->map_x + rc->wall_x;
		floor_wall->y = rc->map_y;
	}
	else
	{
		floor_wall->x = rc->map_x + rc->wall_x;
		floor_wall->y = rc->map_y + 1.0;
	}
	if (rc->draw_end < 0)
		rc->draw_end = d->x.height;
}

void			floorcast(t_data *d, t_raycast *rc, int x)
{
	int			y;
	int			color;
	t_floorcast	fc;

	floorcast_prep(d, rc, &fc.wall);
	y = rc->draw_end;
	while (++y < d->x.height)
	{
		fc.weight = (d->x.height / (2.0 * y - d->x.height)) / rc->perp_wall_dist;
		fc.pos.x = fc.weight * fc.wall.x + (1.0 - fc.weight) * d->player.pos.x;
		fc.pos.y = fc.weight * fc.wall.y + (1.0 - fc.weight) * d->player.pos.y;
	}
}
