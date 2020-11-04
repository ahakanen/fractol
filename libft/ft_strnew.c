/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:46:30 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/18 14:54:43 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/includes/libft.h"

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
