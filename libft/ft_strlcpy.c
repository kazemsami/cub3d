/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:42:51 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/11 14:51:38 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			++i;
		return (i);
	}
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	while (i < dstsize)
		dst[i++] = ' ';
	dst[i] = '\0';
	while (src[i] != '\0')
		++i;
	return (i);
}
