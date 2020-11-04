/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:54:41 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 04:54:51 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
