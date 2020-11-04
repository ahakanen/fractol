/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:52:03 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 02:52:04 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;
	char	*str;

	str = (char *)s;
	pos = ft_strlen(s);
	if (c == '\0')
		return (&str[pos]);
	while (pos-- > 0)
		if (str[pos] == c)
			return (&str[pos]);
	return (0);
}
