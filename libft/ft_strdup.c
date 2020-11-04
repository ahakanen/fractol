/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:39:23 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/16 17:40:58 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *dst;

	dst = (char*)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}
