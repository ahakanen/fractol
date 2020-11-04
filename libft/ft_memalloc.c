/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 03:59:09 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 04:00:58 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
