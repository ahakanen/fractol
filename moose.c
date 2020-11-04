/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:12:05 by ahakanen          #+#    #+#             */
/*   Updated: 2020/06/15 10:53:12 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	check(t_c c, int maxiter)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = 0;
	y = 0;
	while (x * x + y * y <= 4 && i < maxiter)
	{
		tmp = x * x + x - 3 * y * y + c.r;
		y = 5 * x * y + c.i;
		x = tmp;
		i++;
	}
	if (i == maxiter)
		return (255);
	return (i);
}

static void	*thread(void *param)
{
	t_c			c;
	int			end;
	int			i;
	t_tparams	*t;

	t = (t_tparams*)param;
	i = 0 + t->num * t->params->splitsize;
	end = (t->num + 1) * t->params->splitsize;
	while (i < end)
	{
		c = screentocomplex(i % t->params->size, i / t->params->size, \
			*t->params);
		pthread_mutex_lock(&t->params->mutex);
		t->params->check = check(c, t->params->maxiter);
		t->params->img_ptr[i] = t->params->color.b + t->params->check;
		t->params->img_ptr[i + 1] = t->params->color.g + t->params->check;
		t->params->img_ptr[i + 2] = t->params->color.r + t->params->check;
		pthread_mutex_unlock(&t->params->mutex);
		i = i + 4;
	}
	return (NULL);
}

void		moose(t_params params)
{
	pthread_t		threads[CPUCORES];
	t_tparams		tp[CPUCORES];

	params.mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	params.i = 0;
	params.j = 0;
	params.fullscreen = params.size * WIN_Y - 1;
	params.splitsize = (params.fullscreen + 1) / CPUCORES;
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
