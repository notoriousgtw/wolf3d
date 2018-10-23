/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/22 13:14:14 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
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
			if (e.xkey.keycode == KEY_ESC && !(running = false))
				break;
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

void	draw_cube(t_xvars *x)
{
	t_vec3d		p0, p1, p2, p3, p4, p5, p6, p7;
	t_vertlist	v;
	t_linelist	l;
	t_trilist	t;

	p0.x = -0.5;
	p0.y = -0.5;
	p0.z = -0.5;

	p1.x = 0.5;
	p1.y = -0.5;
	p1.z = -0.5;

	p2.x = -0.5;
	p2.y = 0.5;
	p2.z = -0.5;

	p3.x = 0.5;
	p3.y = 0.5;
	p3.z = -0.5;

	p4.x = -0.5;
	p4.y = -0.5;
	p4.z = 0.5;

	p5.x = 0.5;
	p5.y = -0.5;
	p5.z = 0.5;

	p6.x = -0.5;
	p6.y = 0.5;
	p6.z = 0.5;

	p7.x = 0.5;
	p7.y = 0.5;
	p7.z = 0.5;

	kt_vertlist_init(&v);
	kt_vertlist_app(&v, p0);
	kt_vertlist_app(&v, p1);
	kt_vertlist_app(&v, p2);
	kt_vertlist_app(&v, p3);
	kt_vertlist_app(&v, p4);
	kt_vertlist_app(&v, p5);
	kt_vertlist_app(&v, p6);
	kt_vertlist_app(&v, p7);
	kt_vertlist_print(&v);

	double m[4][4];
	kt_mat3d_identity(m);
	kt_tr3d_translate(m, 0, 0, 2);
	// kt_tr3d_scale(m, 0.5, 0.5, 0.5);
	kt_vertlist_transform(&v, m);
	kt_vertlist_print(&v);
	kt_vertlist_screenify(&v, x);

	kt_trilist_init(&t, &v);
	kt_trilist_add(&t, 0, 2, 1);
	kt_trilist_add(&t, 2, 3, 1);
	kt_trilist_add(&t, 1, 3, 5);
	kt_trilist_add(&t, 3, 7, 5);
	kt_trilist_add(&t, 2, 6, 3);
	kt_trilist_add(&t, 3, 6, 7);
	kt_trilist_add(&t, 4, 5, 7);
	kt_trilist_add(&t, 4, 7, 6);
	kt_trilist_add(&t, 0, 4, 2);
	kt_trilist_add(&t, 2, 4, 6);
	kt_trilist_add(&t, 0, 1, 4);
	kt_trilist_add(&t, 1, 5, 4);
	kt_trilist_color(&t, x->white_color);
	kt_vertlist_print(t.verts);
	kt_trilist_print(&t);
	// kt_trilist_draw(&t, x);

	kt_linelist_init(&l, &v);
	kt_linelist_add(&l, 0, 1);
	kt_linelist_add(&l, 1, 3);
	kt_linelist_add(&l, 3, 2);
	kt_linelist_add(&l, 2, 0);
	kt_linelist_add(&l, 0, 4);
	kt_linelist_add(&l, 1, 5);
	kt_linelist_add(&l, 3, 7);
	kt_linelist_add(&l, 2, 6);
	kt_linelist_add(&l, 4, 5);
	kt_linelist_add(&l, 5, 7);
	kt_linelist_add(&l, 7, 6);
	kt_linelist_add(&l, 6, 4);
	kt_linelist_color(&l, x->white_color);
	kt_linelist_print(&l);
	kt_linelist_draw(&l, x);
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

	draw_cube(&d->x);
	XFlush(d->x.dpy);
	/*
	** TODO - Event loop
	*/
	event_loop(d);
	XDestroyWindow(d->x.dpy, d->x.win);
	XCloseDisplay(d->x.dpy);
	return (0);
}
