/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/20 23:29:36 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "keys.h"
#include <stdio.h>

/*
**	Initialises X11 variables and opens up the game window
*/
void	init_window(t_data *d)
{
	XEvent e;
	XSetWindowAttributes wa;

	d->x.dpy = XOpenDisplay(NULL);
	if (d->x.dpy == NULL)
		ft_error("wolf3d: Failed to open display");
	d->x.scr = DefaultScreen(d->x.dpy);
	d->x.black_color = BlackPixel(d->x.dpy, d->x.scr);
	d->x.white_color = WhitePixel(d->x.dpy, d->x.scr);
	d->x.width = 600;
	d->x.height = 600;
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
		if (e.type == MotionNotify)
			printf("MotionNotify x,y = %d,%d\n", e.xmotion.x, e.xmotion.y);
		if (e.type == KeyPress)
		{
			printf("KeyPress == %d\n", e.xkey.keycode);
			if (e.xkey.keycode == KEY_ESC)
				running = false;
		}
		else if (e.type == KeyRelease)
		{
			printf("KeyRelease\n");
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
	init_window(d);
	XSetForeground(d->x.dpy, d->x.gc, d->x.white_color);

	t_vec3d p0, p1, p2, p3;
	p0.x = -0.5;
	p0.y = 0.5;
	p0.z = 1.5;

	p1.x = 0.5;
	p1.y = 0.5;
	p1.z = 1.5;

	p2.x = -0.5;
	p2.y = -0.5;
	p2.z = 1;

	p3.x = 0.5;
	p3.y = -0.5;
	p3.z = 1;

	t_vertlist v;
	kt_vertlist_init(&v);
	kt_vertlist_app(&v, p0);
	kt_vertlist_app(&v, p1);
	kt_vertlist_app(&v, p2);
	kt_vertlist_app(&v, p3);

	t_linelist l;
	kt_linelist_init(&l, &v);
	kt_linelist_app(&l, 0, 1);
	kt_linelist_app(&l, 0, 2);
	kt_linelist_app(&l, 1, 3);
	kt_linelist_app(&l, 2, 3);
	kt_linelist_draw(&l, &d->x, d->x.white_color);

	XFlush(d->x.dpy);
	/*
	** TODO - Event loop
	*/
	event_loop(d);
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
	return (0);
}
