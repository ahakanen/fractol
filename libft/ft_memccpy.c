/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:59:02 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 18:59:53 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		if (ptr[i] == (unsigned char)c)
			return ((void *)dst + i + 1);
		i++;
	}
	return (NULL);
}
