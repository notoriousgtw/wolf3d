/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:37:25 by gwood             #+#    #+#             */
/*   Updated: 2018/10/23 22:44:11 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef	enum	e_event_type
{
	button_press,
	button_release,
	button_held
}				t_event_type;

typedef struct	s_event
{
	t_event_type	type;
	t_event			*next;
}				t_event;

#endif
