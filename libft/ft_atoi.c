/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:15:20 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 01:30:37 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	minus;
	int i;

	if (!str)
		return (0);
	minus = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		minus = minus * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * minus);
}
