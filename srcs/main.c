/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:22:06 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "shapes.h"
#include "color.h"
#include <stdio.h>

/*
**	Initialises X11 variables and opens up the game window
*/
void			kt_create_window(t_data *d)
{
	XEvent e;
	XSetWindowAttributes wa;

	d->x.dpy = XOpenDisplay(NULL);
	if (d->x.dpy == NULL)
		ft_error("wolf3d: Failed to open display");
	d->x.scr = DefaultScreen(d->x.dpy);
	d->x.black_color = BlackPixel(d->x.dpy, d->x.scr);
	d->x.white_color = WhitePixel(d->x.dpy, d->x.scr);
	d->x.width = 1000;
	d->x.height = 1000;
	d->x.win = XCreateSimpleWindow(d->x.dpy, DefaultRootWindow(d->x.dpy), 0, 0,
									d->x.width, d->x.height, 0, d->x.black_color, d->x.black_color);
	XStoreName(d->x.dpy, d->x.win, "wolf3d");
	wa.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | StructureNotifyMask | Button1MotionMask
					| PointerMotionMask;
	XSelectInput(d->x.dpy, d->x.win, wa.event_mask);
	XMapWindow(d->x.dpy, d->x.win);
	d->x.gc = XCreateGC(d->x.dpy, d->x.win, 0, NULL);
	XSetForeground(d->x.dpy, d->x.gc, d->x.white_color);
	while (1)
	{
		XNextEvent(d->x.dpy, &e);
		if (e.type == MapNotify)
			break;
	}
}

void				bb_draw_rect(t_data *d)
{
	t_cube			c;
	double			m[4][4];

	kt_mat3d_identity(m);
	kt_tr3d_rotate(m, 0, 0, 0);
	kt_tr3d_translate(m, 0.3, 0.3, 7);

	bb_rect_init(&c, &d->x, 1.5);
	kt_mesh_color(&c.data, AMETHYST);
	kt_mesh_transform(&c.data, m);
	printf("\n");
	kt_mesh_print_data(&c.data);
	printf("\n");
	kt_mesh_draw_solid(&c.data);
	kt_mesh_color(&c.data, c.data.x->black_color);
	kt_mesh_draw_wire(&c.data);
}

void				kt_draw_cube(t_data *d)
{
	t_cube c;
	double m[4][4];

	kt_mat3d_identity(m);
	kt_tr3d_rotate(m, -45, -45, 0);
	kt_tr3d_translate(m, 0, 0, 2);

	kt_cube_init(&c, &d->x, 1.5);
	kt_mesh_color(&c.data, c.data.x->white_color);
	kt_mesh_transform(&c.data, m);
	printf("\n");
	kt_mesh_print_data(&c.data);
	printf("\n");
	kt_mesh_draw_solid(&c.data);
	kt_mesh_color(&c.data, c.data.x->black_color);
	kt_mesh_draw_wire(&c.data);
}

void			bb_event_loop(t_data *d)
{
	Atom	wm_del_message;
	t_bool	running;
	XEvent	e;

	running = true;
	wm_del_message = XInternAtom(d->x.dpy, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(d->x.dpy, d->x.win, &wm_del_message, 1);
	while (running)
	{
		XNextEvent(d->x.dpy, &e);

		if (e.type == ClientMessage)
		{
			if ((unsigned long) e.xclient.data.l[0] == wm_del_message)
				running = false;
			bb_close(d);
		}
		// if (e.type == MapNotify)
		// 	printf("MapNotify\n");
		// if (e.type == EnterNotify)
		// 	printf("EnterNotify\n");
		// if (e.type == MotionNotify)
		// 	printf("MotionNotify x,y = %d,%d\n", e.xmotion.x, e.xmotion.y);
		if (e.type == KeyPress)
		{
			printf("KeyPress == %d\n", e.xkey.keycode);
			if (e.xkey.keycode == KEY_ESC && !(running = false))
				bb_close(d);
			if (e.xkey.keycode == KEY_SPACE)
			{
				bb_restart(d);
				kt_draw_cube(d);
			}
			if (e.xkey.keycode == KEY_R)
				bb_menu(d);
			if (e.xkey.keycode == KEY_1)
				bb_redraw(d, RED);
			if (e.xkey.keycode == KEY_2)
				bb_redraw(d, AMETHYST);
			if (e.xkey.keycode == KEY_3)
				bb_redraw(d, GREEN);
			if (e.xkey.keycode == KEY_4)
				bb_redraw(d, BLUE);
			// if (e.xkey.keycode == KEY_I)
			// 	d->x.c->color_nbr++;
			// else if (e.xkey.keycode == KEY_O)
			// 	d->x.c->color_nbr--;
		}
		// else if (e.type == KeyRelease)
		// {
		// 	printf("KeyRelease == %d\n", e.xkey.keycode);
		// }
		if (e.type == ButtonPress)
		{
			printf("ButtonPress == %d\n", e.xkey.keycode);
		}
		// else if (e.type == ButtonRelease)
		// {
		// 	printf("ButtonRelease\n");
		// }
	}
}

/*
** Duh
*/
int		main(void)
{
	t_data *d;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		ft_error_unknown("wolf3d: ");
	bb_start(d);
	d->map = bb_parse_map("../maps/basic_room.map");
	XSetForeground(d->x.dpy, d->x.gc, d->x.white_color);
	printf("kt_draw_cube");
	kt_draw_cube(d);
	XFlush(d->x.dpy);
	bb_event_loop(d);
	return (0);
}
