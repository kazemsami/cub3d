/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:22:01 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/16 15:03:58 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	out_of_bounds(t_mlx *mlx, char **map, int i, int z)
{
	if (z < 1 || i < 1 || !map[i + 1] || !map[i][z + 1])
		return (1);
	if (map[i - 1][z + 1] != ' '
		&& map[i - 1][z - 1] != ' '
		&& map[i + 1][z + 1] != ' '
		&& map[i + 1][z - 1] != ' '
		&& map[i + 1][z] != ' '
		&& map[i - 1][z] != ' '
		&& map[i][z - 1] != ' '
		&& map[i][z + 1] != ' ')
	{
		mlx->player.pos_x = (double)i + 0.5;
		mlx->player.pos_y = (double)z + 0.5;
		return (0);
	}
	return (1);
}

int	check_ifone_h(t_mlx *mlx, int i, int z)
{
	int	sv;

	sv = z;
	while (mlx->map.map[i][z])
	{
		if (mlx->map.map[i][z] == '1')
			break ;
		if (mlx->map.map[i][z] == '0')
			return (1);
		z++;
	}
	z = sv;
	while (z >= 0)
	{
		if (mlx->map.map[i][z] == '1')
			break ;
		if (mlx->map.map[i][z] == '0')
			return (1);
		--z;
	}
	return (0);
}

int	check_ifone_v(t_mlx *mlx, int i, int z)
{
	int	sv;

	sv = i;
	while (mlx->map.map[i])
	{
		if (mlx->map.map[i][z] == '1')
			break ;
		if (mlx->map.map[i][z] == '0')
			return (1);
		i++;
	}
	i = sv;
	while (i >= 0)
	{
		if (mlx->map.map[i][z] == '1')
			break ;
		if (mlx->map.map[i][z] == '0')
			return (1);
		--i;
	}
	return (0);
}

static int	closed(char **map, int i, int z)
{
	if (z < 1 || i < 1 || !map[i + 1] || !map[i][z + 1])
		return (1);
	if (map[i - 1][z + 1] != ' '
		&& map[i - 1][z - 1] != ' '
		&& map[i + 1][z + 1] != ' '
		&& map[i + 1][z - 1] != ' ')
		return (0);
	return (1);
}

int	check_closed(t_mlx *mlx)
{
	int	i;
	int	z;

	i = 0;
	while (mlx->map.map[i])
	{
		z = 0;
		while (mlx->map.map[i][z])
		{
			if (mlx->map.map[i][z] == '0')
			{
				if (closed(mlx->map.map, i, z))
					return (1);
			}
			++z;
		}
		++i;
	}
	return (0);
}
