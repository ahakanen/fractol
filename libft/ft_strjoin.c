/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:40:29 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 15:45:11 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	strnew = (char *)ft_memalloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!strnew)
		return (NULL);
	return (ft_strcat(ft_strcat(strnew, str1), str2));
}
