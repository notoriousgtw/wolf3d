/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/19 14:01:02 by gwood            ###   ########.fr       */
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

	d->dpy = XOpenDisplay(NULL);
	if (d->dpy == NULL)
		ft_error("wolf3d: Failed to open display");
	d->scr = DefaultScreen(d->dpy);
	d->black_color = BlackPixel(d->dpy, d->scr);
	d->white_color = WhitePixel(d->dpy, d->scr);
	d->win = XCreateSimpleWindow(d->dpy, DefaultRootWindow(d->dpy), 0, 0,
									480, 480, 0, d->black_color, d->black_color);
	XStoreName(d->dpy, d->win, "wolf3d");
	XSelectInput(d->dpy, d->win, StructureNotifyMask);
	XMapWindow(d->dpy, d->win);
	d->gc = XCreateGC(d->dpy, d->win, 0, NULL);
	XSetForeground(d->dpy, d->gc, d->white_color);
	while (1)
	{
		XNextEvent(d->dpy, &e);
		if (e.type == MapNotify)
			break;
	}
}

void	main_loop(t_data *d)
{
	Atom	wm_del_message;
	t_bool	running;
	XEvent	e;

	wm_del_message = XInternAtom(d->dpy, "WM_DELETE_WINDOW", False);
	XSetWMProtocols(d->dpy, d->win, &wm_del_message, 1);
	while (1)
	{
		XNextEvent(d->dpy, &e);

		if (e.type == ClientMessage)
		{
			if ((unsigned long) e.xclient.data.l[0] == wm_del_message)
				running = false;
			break;
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
	t_vec2d p0;
	t_vec2d p1;
	p0.x = 0;
	p0.y = 0;
	p1.x = 400;
	p1.y = 400;
	kt_drawline2d(d, p0, p1, d->white_color);
	XFlush(d->dpy);
	/*
	** TODO - Event loop
	*/
	main_loop(d);
	sleep(10);
	XDestroyWindow(d->dpy, d->win);
	XCloseDisplay(d->dpy);
	return (0);
}
