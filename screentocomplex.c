/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screentocomplex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:57:10 by ahakanen          #+#    #+#             */
/*   Updated: 2020/02/16 07:58:11 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_c	screentocomplex(int x, int y, t_params params)
{
	t_c	c;

	c.r = ((double)x / (WIN_X * params.zoom)) + params.xoff;
	c.i = ((double)y / (0.5 * WIN_Y * params.zoom)) + params.yoff;
	return (c);
}
