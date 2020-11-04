/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:32:00 by ahakanen          #+#    #+#             */
/*   Updated: 2020/11/04 12:34:02 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	changeiter(int key, t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	if (key == PLUS && params->maxiter < 200)
	{
		params->maxiter++;
	}
	if (key == MINUS && params->maxiter > 0)
	{
		params->maxiter--;
	}
	choosefractal(*params);
	ft_putstr("iterations: |");
	ft_putnbr(params->maxiter);
	ft_putendl("|");
}

static void	move(int key, t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	if (key == LEFT)
	{
		params->xoff = params->xoff + 0.1 / params->zoom;
		choosefractal(*params);
	}
	if (key == RIGHT)
	{
		params->xoff = params->xoff - 0.1 / params->zoom;
		choosefractal(*params);
	}
	if (key == DOWN)
	{
		params->yoff = params->yoff - 0.1 / params->zoom;
		choosefractal(*params);
	}
	if (key == UP)
	{
		params->yoff = params->yoff + 0.1 / params->zoom;
		choosefractal(*params);
	}
}

static void	change(int key, t_params *params)
{
	if (key == MANDELBROT)
	{
		params->fractal = 1;
		ft_putendl("Mandelbrot");
	}
	if (key == JULIA)
	{
		params->fractal = 2;
		ft_putendl("Julia");
	}
	if (key == MOOSE)
	{
		params->fractal = 3;
		ft_putendl("Moose");
	}
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	choosefractal(*params);
}

int			deal_key(int key, void *param)
{
	t_params *params;

	params = (t_params*)param;
	if (key == ESC)
		exit(0);
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move(key, params);
	if (key == PLUS || key == MINUS)
		changeiter(key, params);
	if (key == REDUP || key == REDDOWN || key == GREENUP || \
		key == GREENDOWN || key == BLUEUP || key == BLUEDOWN)
		changecolor(key, params);
	if (key == PSYCH)
		psychtoggle(params);
	if (key == RESET)
		resetcolor(params);
	if (key == MANDELBROT || key == JULIA || key == MOOSE)
		change(key, params);
	return (0);
}
