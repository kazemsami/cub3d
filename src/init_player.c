/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:24:32 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/16 15:25:16 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_westeast(t_mlx *mlx, int west)
{
	if (west)
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = -1;
		mlx->player.plane_x = -0.66;
		mlx->player.plane_y = 0;
	}
	else
	{
		mlx->player.dir_x = 0;
		mlx->player.dir_y = 1;
		mlx->player.plane_x = 0.66;
		mlx->player.plane_y = 0;
	}
}

static void	set_northsouth(t_mlx *mlx, int north)
{
	if (north)
	{
		mlx->player.dir_x = -1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = 0.66;
	}
	else
	{
		mlx->player.dir_x = 1;
		mlx->player.dir_y = 0;
		mlx->player.plane_x = 0;
		mlx->player.plane_y = -0.66;
	}
}

static void	set_player(t_mlx *mlx)
{
	if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'W')
		set_westeast(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'E')
		set_westeast(mlx, 0);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'N')
		set_northsouth(mlx, 1);
	else if (mlx->map.map[(int)mlx->player.pos_x][(int)mlx->player.pos_y]
		== 'S')
		set_northsouth(mlx, 0);
}

void	init_player(t_mlx *mlx)
{
	int	x;
	int	y;

	set_player(mlx);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->buf[y][x] = 0;
			++x;
		}
		++y;
	}
}
