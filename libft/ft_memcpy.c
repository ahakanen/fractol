/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:35:44 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 18:37:24 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!dst || !src)
		return (dst);
	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char*)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}
