/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mousemove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:02:35 by ahakanen          #+#    #+#             */
/*   Updated: 2020/02/28 21:02:36 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_mousemove(int x, int y, void *param)
{
	t_params *params;

	params = (t_params*)param;
	params->mousex = x;
	params->mousey = y;
	if (params->fractal == 2)
	{
		mlx_clear_window(params->win.mlx_ptr, params->win.win_ptr);
		choosefractal(*params);
	}
	if (params->active == 1)
		psych(params);
	return (0);
}
