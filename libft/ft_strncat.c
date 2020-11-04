/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:54:54 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 03:07:26 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(s2);
	dstlen = ft_strlen(s1);
	while (i < srclen && i < n)
	{
		s1[dstlen + i] = s2[i];
		i++;
	}
	s1[dstlen + i] = '\0';
	return (s1);
}
