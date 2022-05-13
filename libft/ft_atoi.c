/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:57:07 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/11 18:24:50 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	sum;
	int				sign;

	sign = 1;
	sum = 0;
	while (*str == 32 || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		return (-1);
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		str++;
		if (sum > 2147483648 && sign == -1)
			return (-1);
		else if (sum > 2147483647 && sign == 1)
			return (-1);
	}
	if (!ft_isdigit(*str) && *str != '\0')
		return (-1);
	return (sum * sign);
}
