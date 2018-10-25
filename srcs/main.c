/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:05:45 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "shapes.h"
#include "color.h"
#include <stdio.h>

/*
**	Initialises X11 variables and opens up the game window
*/
void	create_window(t_data *d)
{
	XEvent e;
	XSetWindowAttributes wa;

	d->x.dpy = XOpenDisplay(NULL);
	if (d->x.dpy == NULL)
		ft_error("wolf3d: Failed to open display");
	d->x.scr = DefaultScreen(d->x.dpy);
	d->x.black_color = BlackPixel(d->x.dpy, d->x.scr);
	d->x.white_color = WhitePixel(d->x.dpy, d->x.scr);
	d->x.width = 1200;
	d->x.height = 1200;
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

void	event_loop(t_data *d)
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
			break;
		}
		if (e.type == MapNotify)
			printf("MapNotify\n");
		if (e.type == EnterNotify)
			printf("EnterNotify\n");
		// if (e.type == MotionNotify)
		// 	printf("MotionNotify x,y = %d,%d\n", e.xmotion.x, e.xmotion.y);
		if (e.type == KeyPress)
		{
			printf("KeyPress == %d\n", e.xkey.keycode);
			if (e.xkey.keycode == KEY_ESC && !(running = false))
				break;
			if (e.xkey.keycode == KEY_SPACE)
				restart(d);
		}
		else if (e.type == KeyRelease)
		{
			printf("KeyRelease == %d\n", e.xkey.keycode);
		}
		if (e.type == ButtonPress)
		{
			printf("ButtonPress == %d\n", e.xkey.keycode);
		}
		else if (e.type == ButtonRelease)
		{
			printf("ButtonRelease\n");
		}
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
	init_pressed(d);
	create_window(d);
	XSetForeground(d->x.dpy, d->x.gc, d->x.white_color);

	double m[4][4];
	kt_mat3d_identity(m);
	kt_tr3d_rotate(m, -45, -45, 0);
	kt_tr3d_translate(m, 0, 0, 2);

	t_cube c;
	kt_cube_init(&c, &d->x, 1.5);
	kt_mesh_color(&c.data, c.data.x->white_color);
	kt_mesh_transform(&c.data, m);
	printf("\n");
	kt_mesh_print_data(&c.data);
	printf("\n");
	kt_mesh_draw_solid(&c.data);
	kt_mesh_color(&c.data, c.data.x->black_color);
	kt_mesh_draw_wire(&c.data);

	XFlush(d->x.dpy);
	/*
	** TODO - Event loop
	*/
	event_loop(d);
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
	return (0);
}
