/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:25:19 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 02:25:30 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!needle || !needle[0])
		return (str1);
	while (str1[i] && i + ft_strlen(str2) <= n)
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			if (str2[j + 1] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
