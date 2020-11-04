/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:13:09 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 03:14:00 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}
