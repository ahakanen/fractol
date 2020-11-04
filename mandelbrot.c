/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:12:05 by ahakanen          #+#    #+#             */
/*   Updated: 2020/06/15 13:44:24 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	check(t_c c, t_params *p)
{
	int			i;
	t_cparams	cparams;

	i = 0;
	cparams.x = 0;
	cparams.y = 0;
	cparams.xx = 0;
	cparams.yy = 0;
	while (cparams.xx + cparams.yy <= 4 && i < p->maxiter)
	{
		cparams.tmp = cparams.xx - cparams.yy + c.r;
		cparams.y = 2 * cparams.x * cparams.y + c.i;
		cparams.x = cparams.tmp;
		cparams.xx = cparams.x * cparams.x;
		cparams.yy = cparams.y * cparams.y;
		i++;
	}
	if (i == p->maxiter)
		return (255);
	return (i);
}

static void	*thread(void *param)
{
	t_c			c;
	int			end;
	int			i;
	int			result;
	t_tparams	*t;

	t = (t_tparams*)param;
	i = 0 + t->num * t->params->splitsize;
	end = (t->num + 1) * t->params->splitsize;
	while (i < end)
	{
		c = screentocomplex(i % t->params->size, i / t->params->size, \
			*t->params);
		result = check(c, t->params);
		t->params->img_ptr[i] = t->params->color.b + result;
		t->params->img_ptr[i + 1] = t->params->color.g + result;
		t->params->img_ptr[i + 2] = t->params->color.r + result;
		i = i + 4;
	}
	return (NULL);
}

void		mandelbrot(t_params params)
{
	pthread_t		threads[CPUCORES];
	t_tparams		tp[CPUCORES];

	params.i = 0;
	params.j = 0;
	while (params.j < CPUCORES)
	{
		tp[params.j].params = &params;
		tp[params.j].num = params.j;
		pthread_create(&threads[params.j], NULL, thread, &tp[params.j]);
		params.j++;
	}
	while (params.i < CPUCORES)
	{
		pthread_join(threads[params.i], NULL);
		params.i++;
	}
	mlx_put_image_to_window(params.win.mlx_ptr, params.win.win_ptr, \
							params.img, 0, 0);
}
