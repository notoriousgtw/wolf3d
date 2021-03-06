/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/11/13 18:06:23 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../includes/shapes.h"
#include "../includes/pipeline.h"
#include "../includes/solid_cube_scene.h"
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
	d->x.color = WHITE;
	d->x.width = 1000;
	d->x.height = 1000;
	d->x.win = XCreateSimpleWindow(d->x.dpy, DefaultRootWindow(d->x.dpy), 0, 0,
									d->x.width, d->x.height, 0,
									BlackPixel(d->x.dpy, d->x.scr),
									BlackPixel(d->x.dpy, d->x.scr));
	XStoreName(d->x.dpy, d->x.win, "wolf3d");
	wa.event_mask = KeyPressMask | KeyReleaseMask | ButtonPressMask
						| ButtonReleaseMask | StructureNotifyMask
						| Button1MotionMask | PointerMotionMask;
	XSelectInput(d->x.dpy, d->x.win, wa.event_mask);
	XMapWindow(d->x.dpy, d->x.win);
	d->x.gc = XCreateGC(d->x.dpy, d->x.win, 0, NULL);
	XSetForeground(d->x.dpy, d->x.gc, WhitePixel(d->x.dpy, d->x.scr));
	while (1)
	{
		XNextEvent(d->x.dpy, &e);
		if (e.type == MapNotify)
			break;
	}
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

void			catch_transforms(t_data *d, XEvent e)
{
	t_bool			change;
	static t_bool	init;
	static double	tr[4][4];
	t_vec3d			offset;

	if (!init)
	{
		kt_mat3d_identity(tr);
		kt_tr3d_translate(tr, 0, 0, 2);
		init = true;
	}
	offset.x = tr[3][0];
	offset.y = tr[3][1];
	offset.z = tr[3][2];
	change = false;
	if (e.xkey.keycode == KEY_RIGHT && (change = true))
		kt_tr3d_translate(tr, 0.1, 0, 0);
	else if (e.xkey.keycode == KEY_LEFT && (change = true))
		kt_tr3d_translate(tr, -0.1, 0, 0);
	else if (e.xkey.keycode == KEY_UP && (change = true))
		kt_tr3d_translate(tr, 0, 0.1, 0);
	else if (e.xkey.keycode == KEY_DOWN && (change = true))
		kt_tr3d_translate(tr, 0, -0.1, 0);
	else if (e.xkey.keycode == KEY_PLUS && (change = true))
		kt_tr3d_translate(tr, 0, 0, 0.1);
	else if (e.xkey.keycode == KEY_MINUS && (change = true))
		kt_tr3d_translate(tr, 0, 0, -0.1);
	else if (e.xkey.keycode == KEY_D && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, 0, 5, 0);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	else if (e.xkey.keycode == KEY_A && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, 0, -5, 0);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	else if (e.xkey.keycode == KEY_W && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, 5, 0, 0);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	else if (e.xkey.keycode == KEY_S && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, -5, 0, 0);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	else if (e.xkey.keycode == KEY_E && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, 0, 0, 5);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	else if (e.xkey.keycode == KEY_Q && (change = true))
	{
		kt_tr3d_translate(tr, -offset.x, -offset.y, -offset.z);
		kt_tr3d_rotate(tr, 0, 0, -5);
		kt_tr3d_translate(tr, offset.x, offset.y, offset.z);
	}
	if (change)
		bb_redraw(d, d->x.color, tr);
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
				kt_solid_cube_scene_draw(&d->scene, NULL, WHITE);
			}
			// if (e.xkey.keycode == KEY_R)
			// {
			// 	XClearWindow(d->x.dpy, d->x.win);
			// 	bb_draw_rect(d);
			// }
			if (e.xkey.keycode == KEY_0)
				bb_redraw(d, WHITE, NULL);
			if (e.xkey.keycode == KEY_1)
				bb_redraw(d, RED, NULL);
			if (e.xkey.keycode == KEY_2)
				bb_redraw(d, AMETHYST, NULL);
			if (e.xkey.keycode == KEY_3)
				bb_redraw(d, GREEN, NULL);
			if (e.xkey.keycode == KEY_4)
				bb_redraw(d, BLUE, NULL);
			catch_transforms(d, e);
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
	// XSetForeground(d->x.dpy, d->x.gc, WHITE);
	kt_solid_cube_scene_init(&d->scene, &d->x, WHITE);
	kt_solid_cube_scene_draw(&d->scene, NULL, WHITE);
	XFlush(d->x.dpy);
	bb_event_loop(d);
	return (0);
}
