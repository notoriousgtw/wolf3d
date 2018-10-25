/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:24:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/24 22:29:33 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# if __APPLE__
#  define KEY_A 8
#  define KEY_B 19
#  define KEY_C 16
#  define KEY_D 10
#  define KEY_E 22
#  define KEY_F 11
#  define KEY_G 13
#  define KEY_H 12
#  define KEY_I 42
#  define KEY_J 46
#  define KEY_K 48
#  define KEY_L 45
#  define KEY_M 54
#  define KEY_N 53
#  define KEY_O 39
#  define KEY_P 43
#  define KEY_Q 20
#  define KEY_R 23
#  define KEY_S 9
#  define KEY_T 25
#  define KEY_U 40
#  define KEY_V 17
#  define KEY_W 21
#  define KEY_X 15
#  define KEY_Y 24
#  define KEY_Z 14
#  define KEY_UP 134
#  define KEY_DOWN 133
#  define KEY_LEFT 131
#  define KEY_RIGHT 132
#  define KEY_SEMI 49
#  define KEY_PLUS 77
#  define KEY_MINUS 86
#  define KEY_SPACE 57
#  define KEY_ESC 61
#  define KEY_TAB 56
#  define KEY_CAPS 65
#  define KEY_SHIFT_L 64
#  define KEY_SHIFT_R 68
#  define KEY_CTRL_L 67
#  define KEY_CTRL_R 70
#  define KEY_ALT_L 66
#  define KEY_ALT_R 69
#  define KEY_ENTER 44
#  define KEY_BACKSPACE 59
# elif __linux__
#  define KEY_A 0
#  define KEY_B 11
#  define KEY_C 8
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_I 34
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37
#  define KEY_M 46
#  define KEY_N 45
#  define KEY_O 31
#  define KEY_P 35
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_S 1
#  define KEY_T 17
#  define KEY_U 32
#  define KEY_V 9
#  define KEY_W 13
#  define KEY_X 7
#  define KEY_Y 16
#  define KEY_Z 6
#  define KEY_UP 134
#  define KEY_DOWN 133
#  define KEY_LEFT 131
#  define KEY_RIGHT 132
#  define KEY_SEMI 49
#  define KEY_PLUS 77
#  define KEY_MINUS 86
#  define KEY_SPACE 65
#  define KEY_ESC 9
#  define KEY_TAB 56
#  define KEY_CAPS 65
#  define KEY_SHIFT_L 64
#  define KEY_SHIFT_R 68
#  define KEY_CTRL_L 67
#  define KEY_CTRL_R 70
#  define KEY_ALT_L 66
#  define KEY_ALT_R 69
#  define KEY_ENTER 44
#  define KEY_BACKSPACE 59
# endif

/*
** ------ FUNCTIONS ------
*/
typedef struct	s_keys
{
	int			w:1;
	int			a:1;
	int			s:1;
	int			d:1;
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
	int			space:1;
	int			esc:1;
}				t_keys;

typedef struct	s_mouse
{
	double		x_pos;
	double		y_pos;
}				t_mouse;

#endif
