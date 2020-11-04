/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:12:48 by ahakanen          #+#    #+#             */
/*   Updated: 2019/11/05 14:13:15 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/includes/libft.h"

static char	*ft_strdupplus(const char *s1)
{
	char	*dst;
	int		dstlen;
	int		i;

	i = 0;
	dstlen = ft_strlen(s1);
	if (!(dst = (char*)malloc(dstlen + 2)))
		return (NULL);
	while (i < dstlen)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	dst[i + 1] = '\0';
	return (dst);
}

static char	*ft_strjoind(char *s1, char *s2)
{
	char		*fresh;
	size_t		i;
	size_t		a;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fresh)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2[a])
	{
		fresh[i] = s2[a];
		i++;
		a++;
	}
	fresh[i] = '\0';
	ft_strdel(&s1);
	return (fresh);
}

static int	read_line(const int fd, char **line, char **old)
{
	char	buf[BUFF_SIZE + 1];
	char	*over;
	int		i;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if ((over = ft_strchr(buf, '\n')))
			break ;
		if (!(*old = ft_strjoind(*old, buf)))
			return (-1);
	}
	if (i == -1 || (i == 0 && *old[0] == '\0'))
		return (i);
	if (i == 0 && *old[0])
	{
		*line = ft_strdupplus(*old);
		ft_strdel(old);
		return ((*line) ? 1 : -1);
	}
	*over = '\0';
	*line = ft_strjoind(*old, buf);
	*old = ft_strdupplus(over + 1);
	return ((!*line || !*old) ? -1 : 1);
}

int			ft_gnl(const int fd, char **line)
{
	static char	*old[MAX_FD];
	char		*over;
	char		*tmp;

	if (BUFF_SIZE < 1 || !line || fd > MAX_FD || read(fd, NULL, 0) == -1)
		return (-1);
	if (!old[fd])
		if (!(old[fd] = ft_strnew(0)))
			return (-1);
	if ((over = ft_strchr(old[fd], '\n')))
	{
		*over = '\0';
		*line = ft_strdupplus(old[fd]);
		tmp = ft_strdupplus(over + 1);
		free(old[fd]);
		old[fd] = tmp;
		return (!*line ? -1 : 1);
	}
	return (read_line(fd, line, &old[fd]));
}
