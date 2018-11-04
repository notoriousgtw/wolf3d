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

#include "../includes/wolf3d.h"
#include "../includes/libft.h"

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

void			bb_free_map(t_map *map)
{
	int			i;

	i = -1;
	while (++i < map->h)
		free(map->cell[i]);
	free(map);
}

static t_map	bb_parser(t_map *map, char **lines, char **cur)
{
	int			r;
	int			c;
	int			c_size;

	map->cell = (int**)ft_memalloc(sizeof(int*) * map->h);
	c_size = map->w;
	r = -1;
	while (lines[++r])
	{
		cur = ft_strsplit(lines[r], ' ');
		map->cell[r] = (int*)ft_memalloc(sizeof(int) * c_size);
		c = -1;
		while (cur[++c])
			map->cell[r][c] = ft_atoi(cur[c]);
	}
	return (*map);
}

t_map			bb_parse_map(const char *file)
{
	char		buf[4097];
	t_map		map;
	int			fd;
	char		**lines;
	char		**cur;

	map.h = 0;
	while (map.h < 4097)
		buf[map.h++] = 0;
	fd = open(file, O_RDONLY);
	read(fd, buf, 4097);
	close(fd);
	map.h = 0;
	lines = ft_strsplit(buf, '\n');
	while (lines[map.h])
	{
		cur = ft_strsplit(lines[map.h], ' ');
		map.w = 0;
		while (cur[map.w])
			map.w++;
		map.h++;
	}
	return (bb_parser(&map, lines, cur));
}
