/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/11/06 16:00:42 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/shapes.h"
#include "../includes/pipeline.h"
#include <stdio.h>

/*
**	Initialises X11 variables and opens up the game window
*/
void			kt_create_window(t_data *d)
{
	XEvent		e;
	XSetWindowAttributes wa;

	d->x.dpy = XOpenDisplay(NULL);
	if (d->x.dpy == NULL)
		ft_error("wolf3d: Failed to open display");
	d->x.scr = DefaultScreen(d->x.dpy);
	d->x.black_color = BlackPixel(d->x.dpy, d->x.scr);
	d->x.white_color = WhitePixel(d->x.dpy, d->x.scr);
	d->x.color = WHITE;
	d->x.width = 1000;
	d->x.height = 1000;
	d->x.win = XCreateSimpleWindow(d->x.dpy, DefaultRootWindow(d->x.dpy), 0, 0,
									d->x.width, d->x.height, 0,
									d->x.black_color, d->x.black_color);
	XStoreName(d->x.dpy, d->x.win, "wolf3d");
	wa.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask
						| ButtonReleaseMask | StructureNotifyMask
						| Button1MotionMask | PointerMotionMask;
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

void			kt_draw_cube(t_data *d, int color)
{
	// t_tri	tri;

	// kt_vert_init(&tri.v0, 100.0, 100.0, 1.0);
	// kt_vert_init(&tri.v1, 200.0, 400.0, 1.0);
	// kt_vert_init(&tri.v2, 400.0, 200.0, 1.0);
	// kt_tri_draw(&d->x, &tri, color);
	// t_meshdata	cube;
	t_meshdata	p0;
	t_meshdata	p1;
	t_pipeline	p;
	t_effect	e;
	double		m[4][4];

	printf("draw_cube\n\n");
	// kt_cube_init_plain_tris(1, &cube);
	kt_plane_init_tris(1, 1, &p0);
	kt_plane_init_tris(1, 1, &p1);

	kt_vs_color_init(&e.vs, m, color);
	kt_gs_default_init(&e.gs);
	kt_ps_color_init(&e.ps);
	e.data = NULL;

	kt_pipeline_init(&p, &d->x);
	p.effect = &e;

	kt_mat3d_identity(p.effect->vs.mat);
	kt_tr3d_rotate(p.effect->vs.mat, 0, -45, 0);
	kt_tr3d_translate(p.effect->vs.mat, -0.5, 0, 2);

	kt_pipeline_draw(&p, &p0);

	kt_mat3d_identity(p.effect->vs.mat);
	kt_tr3d_rotate(p.effect->vs.mat, 0, 45, 0);
	kt_tr3d_translate(p.effect->vs.mat, 0.5, 0, 2);

	kt_pipeline_draw(&p, &p1);
}

void			bb_draw_cube(t_data *d)
{
	t_meshdata	cube;
	t_pipeline	p;
	t_effect	e;
	double		m[4][4];

	printf("draw_cube\n\n");
	kt_cube_init_plain_tris(1, &cube);

	kt_mat3d_identity(m);
	kt_tr3d_rotate(m, -90, -90, 0);
	kt_tr3d_translate(m, 0, 0, 2);

	kt_vs_color_init(&e.vs, m, d->x.color);
	kt_gs_default_init(&e.gs);
	kt_ps_color_init(&e.ps);
	e.data = NULL;

	kt_pipeline_init(&p, &d->x);
	p.effect = &e;
	kt_pipeline_draw(&p, &cube);
}

void			bb_event_loop(t_data *d)
{
	Atom		wm_del_message;
	t_bool		running;
	XEvent		e;

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
				kt_draw_cube(d, WHITE);
			}
			// if (e.xkey.keycode == KEY_R)
			// {
			// 	XClearWindow(d->x.dpy, d->x.win);
			// 	bb_draw_rect(d);
			// }
			if (e.xkey.keycode == KEY_0)
				bb_redraw(d, WHITE);
			if (e.xkey.keycode == KEY_1)
				bb_redraw(d, RED);
			if (e.xkey.keycode == KEY_2)
				bb_redraw(d, AMETHYST);
			if (e.xkey.keycode == KEY_3)
				bb_redraw(d, GREEN);
			if (e.xkey.keycode == KEY_4)
				bb_redraw(d, BLUE);
			// if (e.xkey.keycode == KEY_S)
			// 	bb_splash();
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
			if (e.xkey.keycode == 1)
			{
				XClearWindow(d->x.dpy, d->x.win);
				bb_draw_cube(d);
			}
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
int				main(void)
{
	t_data		*d;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		ft_error_unknown("wolf3d: ");
	bb_start(d);
	// d->map = bb_parse_map("../maps/gj_mod2_f1.map");
	XSetForeground(d->x.dpy, d->x.gc, d->x.white_color);
	kt_draw_cube(d, WHITE);
	XFlush(d->x.dpy);
	bb_event_loop(d);
	return (0);
}
