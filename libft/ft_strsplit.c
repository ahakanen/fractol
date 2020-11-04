/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:29:29 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 22:04:43 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>

static int	ft_wordlen(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**array;

	i = 0;
	j = 0;
	if (!(array = (char **)malloc(ft_wordcount(s, c) * sizeof(char *) + 1)))
		return (NULL);
	while (j < ft_wordcount(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		len = ft_wordlen(s, c, i);
		i = i + len;
		if (!(array[j] = ft_strsub(s, i - len, len)))
		{
			ft_freestrarray(array);
			return (NULL);
		}
		j++;
	}
	array[j] = 0;
	return (array);
}
