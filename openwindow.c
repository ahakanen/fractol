/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:08:40 by ahakanen          #+#    #+#             */
/*   Updated: 2020/06/15 13:37:20 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_params	params_init(void)
{
	t_params	params;

	params.win.mlx_ptr = mlx_init();
	params.win.win_ptr = mlx_new_window(params.win.mlx_ptr, \
						WIN_X, WIN_Y, "fractol");
	params.size = WIN_X * 4;
	params.fullscreen = params.size * WIN_Y - 1;
	params.splitsize = (params.fullscreen + 1) / CPUCORES;
	params.bpp = 32;
	params.endian = END;
	params.maxiter = 32;
	params.xoff = -2;
	params.yoff = -1;
	params.img = mlx_new_image(params.win.mlx_ptr, WIN_X, \
									WIN_Y);
	params.img_ptr = mlx_get_data_addr(params.img, &params.bpp, &params.size, \
									&params.endian);
	params.color.b = 0;
	params.color.g = 0;
	params.color.r = 0;
	params.zoom = 1;
	params.active = 0;
	return (params);
}

void			choosefractal(t_params params)
{
	if (params.fractal == 1)
		mandelbrot(params);
	if (params.fractal == 2)
		julia(params);
	if (params.fractal == 3)
		moose(params);
}

void			openwindow(int fractal)
{
	t_params	params;

	params = params_init();
	params.fractal = fractal;
	choosefractal(params);
	mlx_key_hook(params.win.win_ptr, deal_key, &params);
	mlx_mouse_hook(params.win.win_ptr, deal_mouse, &params);
	mlx_hook(params.win.win_ptr, 6, 1L << 6, deal_mousemove, &params);
	mlx_loop(params.win.mlx_ptr);
}
