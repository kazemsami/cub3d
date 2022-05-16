/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:02:34 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/16 15:43:23 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_y * 0.05)] != '1')
		mlx->player.pos_y += dir_y * 0.05;
}

void	move_down(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_x * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_x * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_y * 0.05)] != '1')
		mlx->player.pos_y -= dir_y * 0.05;
}

void	move_left(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x - dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x -= dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y + dir_x * 0.05)] != '1')
		mlx->player.pos_y += dir_x * 0.05;
}

void	move_right(t_mlx *mlx)
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;

	dir_x = mlx->player.dir_x;
	dir_y = mlx->player.dir_y;
	pos_y = mlx->player.pos_y;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)(pos_x + dir_y * 0.05)][(int)pos_y] != '1')
		mlx->player.pos_x += dir_y * 0.05;
	pos_x = mlx->player.pos_x;
	if (mlx->map.map[(int)pos_x][(int)(pos_y - dir_x * 0.05)] != '1')
		mlx->player.pos_y -= dir_x * 0.05;
}

void	key_function(t_mlx *mlx)
{
	if (mlx->key_a)
		move_left(mlx);
	if (mlx->key_d)
		move_right(mlx);
	if (mlx->key_w)
		move_up(mlx);
	if (mlx->key_s)
		move_down(mlx);
	if (mlx->key_left)
		turn_left(mlx);
	if (mlx->key_right)
		turn_right(mlx);
}
