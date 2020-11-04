/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 06:54:56 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/22 06:55:07 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

/*
** -1 = null delimiter
*/

size_t		ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	if (c == '\0')
		return (-1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i] && s[i - 1] != c)
			return (0);
		while (s[i] != c && s[i])
		{
			i++;
		}
		if (s[i])
			count++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}
