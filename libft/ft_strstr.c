/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:09:03 by ahakanen          #+#    #+#             */
/*   Updated: 2019/10/17 02:24:12 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!needle || !needle[0])
		return (str1);
	while (str1[i])
	{
		j = 0;
		while (str2[j] == str1[i + j])
		{
			if (str2[j + 1] == '\0')
				return (&str1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
