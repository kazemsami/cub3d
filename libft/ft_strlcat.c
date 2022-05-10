/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:00:28 by kabusitt          #+#    #+#             */
/*   Updated: 2021/12/19 14:49:43 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (dst[i])
		++i;
	if (dstsize < i)
	{
		while (src[z])
			++z;
		return (dstsize + z);
	}
	while (dstsize > 0 && src[z] && i < dstsize - 1)
	{
		dst[i++] = src[z++];
	}
	dst[i] = '\0';
	while (src[z++])
		++i;
	return (i);
}
