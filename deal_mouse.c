/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:18:22 by ahakanen          #+#    #+#             */
/*   Updated: 2020/06/15 11:13:18 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	resetzoom(t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	params->zoom = 1;
	choosefractal(*params);
	ft_putendl("Zoom reset");
}

static void	zoom(int button, t_params *params)
{
	if (button == 5 && params->zoom > 1)
	{
		mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
		params->zoom = params->zoom - 0.1;
		choosefractal(*params);
	}
	if (button == 4)
	{
		mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
		params->zoom = params->zoom + 0.1;
		choosefractal(*params);
	}
	ft_putstr("Zoom: |");
	ft_putnbr(params->zoom);
	ft_putendl("|");
}

int			deal_mouse(int button, int x, int y, void *param)
{
	t_params *params;

	x = y;
	y = x;
	params = (t_params*)param;
	if (button == 4 || button == 5)
		zoom(button, params);
	if (button == 3)
		resetzoom(params);
	return (0);
}
