/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:45 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/16 15:29:52 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	calc_step(t_mlx *mlx)
{
	if (mlx->ray.raydir_x < 0)
	{
		mlx->ray.step_x = -1;
		mlx->ray.sidedist_x = (mlx->player.pos_x - mlx->ray.map_x)
			* mlx->ray.deltadist_x;
	}
	else
	{
		mlx->ray.step_x = 1;
		mlx->ray.sidedist_x = (mlx->ray.map_x + 1.0 - mlx->player.pos_x)
			* mlx->ray.deltadist_x;
	}
	if (mlx->ray.raydir_y < 0)
	{
		mlx->ray.step_y = -1;
		mlx->ray.sidedist_y = (mlx->player.pos_y - mlx->ray.map_y)
			* mlx->ray.deltadist_y;
	}
	else
	{
		mlx->ray.step_y = 1;
		mlx->ray.sidedist_y = (mlx->ray.map_y + 1.0 - mlx->player.pos_y)
			* mlx->ray.deltadist_y;
	}
}

void	dda(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (mlx->ray.sidedist_x < mlx->ray.sidedist_y)
		{
			mlx->ray.sidedist_x += mlx->ray.deltadist_x;
			mlx->ray.map_x += mlx->ray.step_x;
			mlx->ray.side = 0;
		}
		else
		{
			mlx->ray.sidedist_y += mlx->ray.deltadist_y;
			mlx->ray.map_y += mlx->ray.step_y;
			mlx->ray.side = 1;
		}
		if (mlx->map.map[mlx->ray.map_x][mlx->ray.map_y] == '1')
			hit = 1;
	}
}
