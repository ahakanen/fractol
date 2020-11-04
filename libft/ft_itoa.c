/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:55:05 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 15:55:13 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static char	*ft_itoahelp(int n, char *str, int nbrslot)
{
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	if (n < 10)
	{
		str[nbrslot] = (n + 48);
	}
	else
	{
		ft_itoahelp(n / 10, str, nbrslot - 1);
		str[nbrslot] = (n % 10 + 48);
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*minint;
	char	*str;

	minint = "-2147483648";
	if (n == ft_maxint(0))
	{
		if (!(str = ft_strnew(11)))
			return (NULL);
		str = ft_strcpy(str, minint);
		return (str);
	}
	if (n < 0)
	{
		if (!(str = ft_strnew(ft_nbrsize(n) + 1)))
			return (NULL);
		return (ft_itoahelp(n, str, ft_nbrsize(n)));
	}
	if (!(str = ft_strnew(ft_nbrsize(n))))
		return (NULL);
	return (ft_itoahelp(n, str, ft_nbrsize(n) - 1));
}
