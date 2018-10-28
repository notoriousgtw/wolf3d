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

void				bb_menu(t_data *d)
{
	XClearWindow(d->x.dpy, d->x.win);
	bb_draw_rect(d);
}

void				bb_init_color_table(t_color *color, int color_nbr)
{
	int				i;
	float			f;

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

void				bb_restart(t_data *d)
{
	ft_putendl("restart");
	bb_close(d);
	bb_start(d);
}

void				bb_close(t_data *d)
{
	ft_putendl("close");
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
}

void				bb_start(t_data *d)
{
	ft_putendl("start");
	bb_init_pressed(d);
	bb_init_colors(d);
	kt_create_window(d);
}

void				bb_init_pressed(t_data *d)
{
	d->changed = 1;
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

void				bb_redraw(t_data *d, int solid)//, int wire)
{
	XClearWindow(d->x.dpy, d->x.win);
	d->x.white_color = solid;
	// d->x.black_color = wire;
	kt_draw_cube(d);
}


void				bb_init_color_tab(t_color *color)
{
	int				i;

	color->color = (u_int8_t*)ft_memalloc(sizeof(u_int8_t) * 255);
	color->r = ((u_int8_t*)ft_memalloc(sizeof(u_int8_t) * 4));
	color->g = ((u_int8_t*)ft_memalloc(sizeof(u_int8_t) * 4));
	color->b = ((u_int8_t*)ft_memalloc(sizeof(u_int8_t) * 4));
	color->r[0] = (u_int8_t)(PURPLE >> 16 & 0xFF);
	color->r[1] = (u_int8_t)(AMETHYST >> 16 & 0xFF);
	color->g[0] = (u_int8_t)(PURPLE >> 8 & 0xFF);
	color->g[1] = (u_int8_t)(AMETHYST >> 8 & 0xFF);
	color->b[0] = (u_int8_t)(PURPLE & 0xFF);
	color->b[1] = (u_int8_t)(AMETHYST & 0xFF);
	i = -1;
	while (++i < 255)
	{
		color->r[2] = ((u_int8_t)(color->r[0] * i) / 255) + ((u_int8_t)(color->r[1] * (255 - i)) / 255);
		color->g[2] = ((u_int8_t)(color->g[0] * i) / 255) + ((u_int8_t)(color->g[1] * (255 - i)) / 255);
		color->b[2] = ((u_int8_t)(color->b[0] * i) / 255) + ((u_int8_t)(color->b[1] * (255 - i)) / 255);
		color->color[i] = (u_int8_t)color->r[2] << 16 | (u_int8_t)color->g[2] << 8 | (u_int8_t)color->b[2];
	}
}

void				bb_init_colors(t_data *data)
{
	int				color;

	color = 64;
	if (!(data->x.c = (t_color*)ft_memalloc(sizeof(t_color) * color)))
		ft_error_unknown("wolf3d: ");
	bb_init_color_table(data->x.c, color);
}
