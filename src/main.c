/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:19 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/16 15:32:33 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_loop(t_mlx *mlx)
{
	process(mlx);
	draw(mlx);
	key_function(mlx);
	return (0);
}

void	init_map(t_mlx *mlx)
{
	mlx->map.wtexture = 0;
	mlx->map.etexture = 0;
	mlx->map.stexture = 0;
	mlx->map.ntexture = 0;
	mlx->map.fcolor = 0;
	mlx->map.ccolor = 0;
	mlx->map.max = 0;
	mlx->map.map = NULL;
}

void	init_keys(t_mlx *mlx)
{
	mlx->key_a = 0;
	mlx->key_d = 0;
	mlx->key_s = 0;
	mlx->key_w = 0;
	mlx->key_left = 0;
	mlx->key_right = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.size_l, &mlx->img.endian);
	mlx_loop_hook(mlx->mlx_ptr, draw_loop, mlx);
	mlx_hook(mlx->win, 2, 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 0, key_release, mlx);
	mlx_hook(mlx->win, 17, 0, exit_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		init_map(&mlx);
		if (loadmap(&mlx, argv[1]))
		{
			free_map(&mlx);
			return (1);
		}
		init_player(&mlx);
		init_keys(&mlx);
		init_mlx(&mlx);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments", 2);
		return (1);
	}
}