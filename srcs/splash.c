/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:43:29 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/22 19:43:29 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <math.h>
#include <stdio.h>

void			bb_splash_putendl(void)
{
	ft_putendl("\n\n\t\t _________   ____ ________ __________________");
	ft_putendl("\t\t|\\ _______\\ |\\ __\\\\ ______\\ _________________\\");
	ft_putendl("\t\t| |       | | |  //       /                  |");
	ft_putendl("\t\t| |       | | | //       /                   |");
	ft_putendl("\t\t| |       |  \\|//       /__         _________|");
    ft_putendl("\t\t| |       |   //       / | |       |");
    ft_putendl("\t\t| |       |  //       /  | |       |");
    ft_putendl("\t\t| |       | //       /   | |       |");
    ft_putendl("\t\t| |       |//       /    | |       |");
    ft_putendl("\t\t| |       |/       /     | |       |");
    ft_putendl("\t\t| |               /      | |       |");
    ft_putendl("\t\t| |              /       | |       |");
    ft_putendl("\t\t| |             |        | |       |");
    ft_putendl("\t\t| |              \\       | |       |");
    ft_putendl("\t\t| |               \\      | |       |");
    ft_putendl("\t\t| |       |\\       \\     | |       |");
    ft_putendl("\t\t| |       | \\       \\    | |       |");
    ft_putendl("\t\t| |       |\\ \\       \\   | |       |");
    ft_putendl("\t\t| |       | \\ \\       \\  | |       |");
    ft_putendl("\t\t| |       |  \\ \\       \\ | |       |");
    ft_putendl("\t\t| |       |   \\ \\       \\| |       |");
    ft_putendl("\t\t| |       |    \\ \\       \\ |       |");
    ft_putendl("\t\t \\|_______|     \\_\\_______\\|_______|\n\n");
}

void            bb_splash_name(void)
{
    ft_putendl("\n\n\t __   __  ________   __     __   __        __     __");
    ft_putendl("\t|  | / / |__    __| |  |   |  | |  |      |  |   |  |");
    ft_putendl("\t|  |/ /     |  |    |  |   |  | |  |      |  |   |  |");
    ft_putendl("\t|    |      |  |    |  |   |  | |  |      |  |   |  |");
    ft_putendl("\t|  |\\ \\     |  |    |   \\_/   | |  |____  |   \\_/   |");
    ft_putendl("\t|__| \\_\\    |__|     \\_______/  |_______|  \\_______/");
    ft_putendl("\n\n\n");
}

void            bb_splash(void)
{
    bb_splash_putendl();
	bb_splash_name();
}