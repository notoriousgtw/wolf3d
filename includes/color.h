/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:40:52 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/24 22:14:52 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED 0xFF2222
# define GREEN 0x22FF22
# define BLUE 0x2222FF
# define PURPLE 0xFF22FF
# define WHITE 0xFFFFFF
# define GREY 0xAAAAAA
# define DGREY 0x444444
# define AMETHYST 0x6C2DC7
# define G_APPLE 0x4CC417
# define B_ORCHID 0x1F45FC

typedef struct		s_color
{
	u_int8_t		r;
	u_int8_t		g;
	u_int8_t		b;
	int				color_nbr;
}					t_color;

#endif
