/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 05:15:11 by ahakanen          #+#    #+#             */
/*   Updated: 2020/02/16 05:15:14 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putendl("usage: ./fractol fractalname");
	ft_putendl("____________________________");
	ft_putendl("available fractals:");
	ft_putendl("mandelbrot");
	ft_putendl("julia");
	ft_putendl("moose");
	exit(1);
}

static void	checkarg(char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
		openwindow(1);
	else if (ft_strcmp(arg, "julia") == 0)
		openwindow(2);
	else if (ft_strcmp(arg, "moose") == 0)
		openwindow(3);
	else
		usage();
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	checkarg(argv[1]);
	return (0);
}
