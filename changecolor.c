/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changecolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:50:52 by ahakanen          #+#    #+#             */
/*   Updated: 2020/02/28 15:50:53 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	printcolorinfo(t_params *params)
{
	ft_putendl("Color Base:");
	ft_putstr("B: |");
	ft_putnbr(params->color.b);
	ft_putstr("|	");
	ft_putstr("G: |");
	ft_putnbr(params->color.g);
	ft_putstr("|	");
	ft_putstr("R: |");
	ft_putnbr(params->color.r);
	ft_putendl("|");
}

static void	blue(int key, t_params *params)
{
	if (key == BLUEUP)
	{
		if (params->color.b == 255)
			params->color.b = 0;
		else
			params->color.b++;
		choosefractal(*params);
	}
	if (key == BLUEDOWN)
	{
		if (params->color.b == 0)
			params->color.b = 255;
		else
			params->color.b--;
		choosefractal(*params);
	}
}

static void	green(int key, t_params *params)
{
	if (key == GREENUP)
	{
		if (params->color.g == 255)
			params->color.g = 0;
		else
			params->color.g++;
		choosefractal(*params);
	}
	if (key == GREENDOWN)
	{
		if (params->color.g == 0)
			params->color.g = 255;
		else
			params->color.g--;
		choosefractal(*params);
	}
}

static void	red(int key, t_params *params)
{
	if (key == REDUP)
	{
		if (params->color.r == 255)
			params->color.r = 0;
		else
			params->color.r++;
		choosefractal(*params);
	}
	if (key == REDDOWN)
	{
		if (params->color.r == 0)
			params->color.r = 255;
		else
			params->color.r--;
		choosefractal(*params);
	}
}

void		changecolor(int key, t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	if (key == BLUEUP || key == BLUEDOWN)
		blue(key, params);
	if (key == GREENUP || key == GREENDOWN)
		green(key, params);
	if (key == REDUP || key == REDDOWN)
		red(key, params);
	printcolorinfo(params);
}
