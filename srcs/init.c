/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:43:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/22 19:43:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>
#include <stdio.h>

void			bb_menu(t_data *d)
{
	XClearWindow(d->x.dpy, d->x.win);
	kt_draw_cube(d);
}

void			bb_init_color_table(t_color *color, int color_nbr)
{
	int			i;
	float		f;

	color->color = (u_int8_t*)ft_memalloc(sizeof(u_int8_t) * color_nbr);
	f = 0;
	i = -1;
	while (++i < color_nbr)
	{
		color->red = (cos(f) + 1) * 127;
		color->green = (sin(f) + 1) * 127;
		color->blue = (-cos(f) + 1) * 127;
		color->color[i] = color->red | color->green << 8 | color->blue << 16;
		f = M_PI / color_nbr;
	}
	color->color_nbr = color_nbr;
}

void			bb_restart(t_data *d)
{
	printf("\n  * * * * *  \n*\t    *\n*  ");
	printf("Restart  *\n*\t    *\n  * * * * *  \n\n");
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
	bb_init_data(d);
	bb_init_colors(d);
	kt_create_window(d);
}

void			bb_close(t_data *d)
{
	printf("\n  * * * * *  \n*\t    *\n*   ");
	printf("Close   *\n*\t    *\n  * * * * *  \n");
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
}

void			bb_start(t_data *d)
{
	bb_splash();
	printf("\n  * * * * *  \n*\t    *\n*   ");
	printf("Start   *\n*\t    *\n  * * * * *  \n\n");
	bb_init_data(d);
	bb_init_colors(d);
	kt_create_window(d);
}

void			bb_init_data(t_data *d)
{
	d->player.pos.x = 2;
	d->player.pos.y = 2;
	d->player.dir.x = -1;
	d->player.dir.x = 0;
	d->player.plane.x = 0;
	d->player.plane.y = 0.66;
	d->mouse_x = 0;
	d->mouse_y = 0;
	d->t.cur = 0;
	d->t.cur_sec = 0;
	d->t.old = 0;
	d->t.past = 0;
	bb_init_pressed(d);
}

void			bb_init_pressed(t_data *d)
{
	d->pressed.w = 0;
	d->pressed.a = 0;
	d->pressed.s = 0;
	d->pressed.d = 0;
	d->pressed.up = 0;
	d->pressed.down = 0;
	d->pressed.left = 0;
	d->pressed.right = 0;
	d->pressed.esc = 0;
	d->pressed.space = 0;
}

void			bb_redraw(t_data *d, int solid)//, int wire)
{
	XClearWindow(d->x.dpy, d->x.win);
	d->x.white_color = solid;
	// d->x.black_color = wire;
	kt_draw_cube(d);
	// bb_draw_cube(d);
}

void			bb_init_colors(t_data *data)
{
	int			color;

	color = 64;
	if (!(data->x.c = (t_color*)ft_memalloc(sizeof(t_color) * color)))
		ft_error_unknown("wolf3d: ");
	bb_init_color_table(data->x.c, color);
}
