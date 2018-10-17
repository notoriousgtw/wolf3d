/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/17 14:01:15 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include "libft.h"
#include <stdio.h>

int	main()
{
	Display	*dpy;
	int 	scr;
	Window	win;
	GC		gc;

	/* open connection with the server */
	dpy = XOpenDisplay(NULL);
	if(dpy == NULL)
	{
		printf("Cannot open display\n");
		exit(1);
	}
	scr = DefaultScreen(dpy);
	/* create window */
	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 200, 200, 10, WhitePixel(dpy, scr), BlackPixel(dpy, scr));
	/* map (show) the window */
	XMapRaised(dpy, win);
	/* create graphics context */
	gc = XCreateGC(dpy, win, 0, NULL);
	/* tell gc we're drawing with white */
	XSetForeground(dpy, gc, WhitePixel(dpy, scr));
	/* event loop */
	while (1)
	{
		XEvent e;
	    XNextEvent(dpy, &e);
	    if (e.type == MapNotify)
			break;
	}
	sleep(10);
	/* destroy our window */
	XDestroyWindow(dpy, win);
	/* close connection to server */
	XCloseDisplay(dpy);
	return (0);
}
