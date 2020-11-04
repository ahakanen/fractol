/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:21:05 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/19 01:22:38 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t result;

	i = 0;
	j = 0;
	result = 0;
	i = ft_strlen(dst);
	result = ft_strlen(src);
	if (dstsize == 0)
		return (result);
	if (dstsize <= i)
		return (result + dstsize);
	else
		result = result + i;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
