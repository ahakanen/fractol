/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:47:51 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 23:51:32 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char *str1;
	char *str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	return (0);
}
