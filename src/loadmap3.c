/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:01:57 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:02:20 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_south(t_mlx *mlx, char *str)
{
	if (!mlx->map.stexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.s_texture = ft_strdup(str);
		mlx->map.stexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_north(t_mlx *mlx, char *str)
{
	if (!mlx->map.ntexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.n_texture = ft_strdup(str);
		mlx->map.ntexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_west(t_mlx *mlx, char *str)
{
	if (!mlx->map.wtexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.w_texture = ft_strdup(str);
		mlx->map.wtexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_east(t_mlx *mlx, char *str)
{
	if (!mlx->map.etexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.e_texture = ft_strdup(str);
		mlx->map.etexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_fcolor(t_mlx *mlx, char *str)
{
	if (!mlx->map.fcolor)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.floor_color = ft_strdup(str);
		mlx->map.fcolor = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}
