/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:20:46 by kabusitt          #+#    #+#             */
/*   Updated: 2021/12/27 12:46:06 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		++i;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

static char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(str))
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dststr;
	const char	*srcstr;

	if (dst == src)
		return (dst);
	dststr = (char *)dst;
	srcstr = (const char *)src;
	if (srcstr < dststr)
	{
		while (len--)
			dststr[len] = srcstr[len];
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		dststr[i] = srcstr[i];
		++i;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
	if (!s1 && s2)
		return (ft_strdup(s2));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
