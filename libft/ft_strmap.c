/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:20:17 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 15:34:01 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
