/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:05:53 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:06:02 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	elements_exist(t_mlx *mlx, int isnot)
{
	if (isnot)
	{
		if (!mlx->map.ntexture && !mlx->map.stexture
			&& !mlx->map.wtexture && !mlx->map.etexture
			&& !mlx->map.fcolor && !mlx->map.ccolor)
			return (1);
		return (0);
	}
	else
	{
		if (mlx->map.ntexture && mlx->map.stexture
			&& mlx->map.wtexture && mlx->map.etexture
			&& mlx->map.fcolor && mlx->map.ccolor)
			return (1);
		return (0);
	}
}

int	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		++i;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'N' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != 'S'
			&& str[i] != ' ')
			return (0);
		++i;
	}
	if (str[i + 1] == '\n')
		return (2);
	return (1);
}

int	cpy_map(t_mlx *mlx, char **strs, int max)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (!is_map(strs[i]))
			return (1);
		ft_strlcpy(mlx->map.map[i], strs[i], max);
		++i;
	}
	return (0);
}

int	find_max(char **strs)
{
	int		i;
	int		max;
	int		z;

	i = 0;
	while (strs[i])
	{
		z = 0;
		while (strs[i][z])
			++z;
		if (z > max)
			max = z;
		++i;
	}
	return (max);
}

int	check_filecont(char *file_cont)
{
	if (!file_cont)
	{
		ft_putstr_fd("Error\nFailed to read map file or "
			"map file is too large.\n", 2);
		return (1);
	}
	if (ft_strlen(file_cont) > 1000)
	{
		ft_putstr_fd("Error\nMap file is too large.\n", 2);
		return (1);
	}
	if (check_nonewline(file_cont))
	{
		ft_putstr_fd("Error\nMap contains newline.\n", 2);
		return (1);
	}
	return (0);
}
