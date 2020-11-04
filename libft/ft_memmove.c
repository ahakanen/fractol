/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:22 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 19:58:41 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dst || !src)
		return (NULL);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str2 < str1)
		while (n--)
			str1[n] = str2[n];
	else
		ft_memcpy(str1, str2, n);
	return (dst);
}
