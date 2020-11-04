/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:31:59 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/16 23:32:08 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	while (i < srclen || i < dstlen)
	{
		if (i >= srclen && dstlen > srclen)
		{
			dst[i] = '\0';
			i++;
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
