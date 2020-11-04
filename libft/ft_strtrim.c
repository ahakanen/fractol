/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 00:38:52 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/19 00:43:05 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	int		start;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]) == 1)
		i++;
	start = i;
	if (ft_strlen(s) <= i)
	{
		str = ft_strnew(0);
		return (str);
	}
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) == 1)
		i--;
	if (!(str = ft_strsub(s, start, i - start + 1)))
		return (NULL);
	return (str);
}
