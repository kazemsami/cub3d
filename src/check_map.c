/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:21:57 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/14 16:01:30 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_repeat(t_mlx *mlx)
{
	int	i;
	int	z;
	int	found;

	i = 0;
	found = 0;
	while (mlx->map.map[i])
	{
		z = 0;
		while (mlx->map.map[i][z])
		{
			if (mlx->map.map[i][z] == 'E' || mlx->map.map[i][z] == 'N'
				|| mlx->map.map[i][z] == 'W' || mlx->map.map[i][z] == 'S')
			{
				if (out_of_bounds(mlx, mlx->map.map, i, z))
					return (1);
				found++;
			}
			++z;
		}
		++i;
	}
	if (found != 1)
		return (1);
	return (0);
}

static int	check_spaces(t_mlx *mlx)
{
	int	i;
	int	z;

	i = 0;
	while (mlx->map.map[i])
	{
		z = 0;
		while (mlx->map.map[i][z])
		{
			if (mlx->map.map[i][z] == ' ')
			{
				if (check_ifone_v(mlx, i, z))
					return (1);
				if (check_ifone_h(mlx, i, z))
					return (1);
			}
			++z;
		}
		++i;
	}
	return (0);
}

static int	check_top_bot(t_mlx *mlx)
{
	int	z;

	z = 0;
	while (mlx->map.map[0][z])
	{
		if (mlx->map.map[0][z] == ' ' || mlx->map.map[0][z] == '1')
			;
		else
			return (1);
		++z;
	}
	z = 0;
	while (mlx->map.map[mlx->map.size - 1][z])
	{
		if (mlx->map.map[mlx->map.size - 1][z] == ' '
			|| mlx->map.map[mlx->map.size - 1][z] == '1')
			;
		else
			return (1);
		++z;
	}
	return (0);
}

static int	check_sides(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->map.map[i])
	{
		if (mlx->map.map[i][0] == ' ' || mlx->map.map[i][0] == '1')
			;
		else
			return (1);
		++i;
	}
	i = 0;
	while (mlx->map.map[i])
	{
		if (mlx->map.map[i][mlx->map.max - 1] == ' '
			|| mlx->map.map[i][mlx->map.max - 1] == '1')
			;
		else
			return (1);
		++i;
	}
	return (0);
}

int	check_map(t_mlx *mlx)
{
	if (mlx->map.max < 3 || mlx->map.size < 3)
		return (1);
	if (check_spaces(mlx))
		return (1);
	if (check_top_bot(mlx))
		return (1);
	if (check_sides(mlx))
		return (1);
	if (check_repeat(mlx))
		return (1);
	if (check_closed(mlx))
		return (1);
	return (0);
}
