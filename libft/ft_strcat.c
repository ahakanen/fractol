/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 01:39:46 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 01:53:58 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int	dstlen;

	i = 0;
	dstlen = ft_strlen(s1);
	while (s1[i])
	{
		s1[dstlen + i] = s2[i];
		i++;
	}
	s1[dstlen + i] = '\0';
	return (s1);
}
