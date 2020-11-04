/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:34:13 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 15:34:17 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
