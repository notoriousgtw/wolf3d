/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:44:01 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/26 16:44:02 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** imports for read
*/
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

/*
** imports for open
*/
#include <fcntl.h>
#include <stdio.h>

/*
** imports for malloc
*/
#include <stdlib.h>

t_map				parse_map(const char file)
{
	char			buf[4097];
	t_map			map;
	int				fd;

	map.h = 0;
	while (map.h < 4097)
		buf[map.h++] = 0;
}
