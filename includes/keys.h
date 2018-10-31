/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:24:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/25 19:24:22 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

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

#if  __APPLE__
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
#  define KEY_1 26
#  define KEY_2 27
#  define KEY_3 28
#  define KEY_4 29
#  define KEY_5 31
#  define KEY_6 30
#  define KEY_7 34
#  define KEY_8 36
#  define KEY_9 33
#  define KEY_0 37
# elif __linux__
#  define KEY_A 38
#  define KEY_B 56
#  define KEY_C 54
#  define KEY_D 40
#  define KEY_E 26
#  define KEY_F 41
#  define KEY_G 42
#  define KEY_H 43
#  define KEY_I 31
#  define KEY_J 44
#  define KEY_K 45
#  define KEY_L 46
#  define KEY_M 58
#  define KEY_N 57
#  define KEY_O 32
#  define KEY_P 33
#  define KEY_Q 24
#  define KEY_R 27
#  define KEY_S 39
#  define KEY_T 28
#  define KEY_U 30
#  define KEY_V 55
#  define KEY_W 25
#  define KEY_X 53
#  define KEY_Y 29
#  define KEY_Z 52
#  define KEY_UP 111
#  define KEY_DOWN 116
#  define KEY_LEFT 113
#  define KEY_RIGHT 114
#  define KEY_SEMI 47
#  define KEY_PLUS 86
#  define KEY_MINUS 82
#  define KEY_SPACE 65
#  define KEY_ESC 9
#  define KEY_TAB 23
#  define KEY_CAPS 66
#  define KEY_SHIFT_L 50
#  define KEY_SHIFT_R 62
#  define KEY_CTRL_L 37
#  define KEY_CTRL_R 105
#  define KEY_ALT_L 64
#  define KEY_ALT_R 108
#  define KEY_ENTER 36
#  define KEY_BACKSPACE 22
#  define KEY_1 10
#  define KEY_2 11
#  define KEY_3 12
#  define KEY_4 13
#  define KEY_5 14
#  define KEY_6 15
#  define KEY_7 16
#  define KEY_8 17
#  define KEY_9 18
#  define KEY_0 19

#endif
