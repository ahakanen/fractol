/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:00:22 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 20:04:11 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
		{
			return (tmp + i);
		}
		i++;
	}
	return (NULL);
}
