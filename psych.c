/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psych.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:33:14 by ahakanen          #+#    #+#             */
/*   Updated: 2020/02/28 17:33:15 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	resetcolor(t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	params->color.b = 0;
	params->color.g = 0;
	params->color.r = 0;
	choosefractal(*params);
	ft_putendl("Color Reset");
}

void	psych(t_params *params)
{
	mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
	params->color.b = (params->color.b + 125) % 255;
	params->color.g = (params->color.g + params->color.b + 55) % 255;
	params->color.r = (params->color.r + params->color.g + 30) % 255;
	choosefractal(*params);
}

void	psychtoggle(t_params *params)
{
	if (params->active == 1)
	{
		params->active = 0;
		ft_putendl("psych deactivated");
	}
	else
	{
		params->active = 1;
		ft_putendl("psych activated");
	}
}
