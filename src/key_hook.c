/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:12:38 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/19 19:29:56 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x
		* cos(-0.05) - mlx->player.dir_y * sin(-0.05);
	mlx->player.dir_y = olddir_x * sin(-0.05) + mlx->player.dir_y * cos(-0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x
		* cos(-0.05) - mlx->player.plane_y * sin(-0.05);
	mlx->player.plane_y = oldplane_x
		* sin(-0.05) + mlx->player.plane_y * cos(-0.05);
}

void	turn_left(t_mlx *mlx)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = mlx->player.dir_x;
	mlx->player.dir_x = mlx->player.dir_x
		* cos(0.05) - mlx->player.dir_y * sin(0.05);
	mlx->player.dir_y = olddir_x
		* sin(0.05) + mlx->player.dir_y * cos(0.05);
	oldplane_x = mlx->player.plane_x;
	mlx->player.plane_x = mlx->player.plane_x
		* cos(0.05) - mlx->player.plane_y * sin(0.05);
	mlx->player.plane_y = oldplane_x
		* sin(0.05) + mlx->player.plane_y * cos(0.05);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		mlx->key_a = 1;
	else if (keycode == KEY_S)
		mlx->key_s = 1;
	else if (keycode == KEY_W)
		mlx->key_w = 1;
	else if (keycode == KEY_D)
		mlx->key_d = 1;
	else if (keycode == KEY_ESC)
		exit_hook(mlx);
	else if (keycode == KEY_LEFT)
		mlx->key_left = 1;
	else if (keycode == KEY_RIGHT)
		mlx->key_right = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_A)
		mlx->key_a = 0;
	else if (keycode == KEY_S)
		mlx->key_s = 0;
	else if (keycode == KEY_W)
		mlx->key_w = 0;
	else if (keycode == KEY_D)
		mlx->key_d = 0;
	else if (keycode == KEY_ESC)
		exit_hook(mlx);
	else if (keycode == KEY_LEFT)
		mlx->key_left = 0;
	else if (keycode == KEY_RIGHT)
		mlx->key_right = 0;
	return (0);
}

int	do_map(t_mlx *mlx, char **strs, int i)
{
	if (iselement(&(*strs)[i]))
	{
		if (check_elements(mlx, &(*strs)[i]))
			return (1);
	}
	else if (is_map(*strs) && elements_exist(mlx))
	{
		if (validate_map(mlx, strs))
			return (1);
		return (2);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid characters in the map "
			"or fields are missing\n", 2);
		return (1);
	}
	return (0);
}
