/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:19 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:45:02 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	process(t_mlx *mlx)
{
	int	w;
	int	h;

	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			mlx->img.data[h * WIDTH + w] = 0xFFFFFF;
			w++;
		}
		++h;
	}
}

void	draw(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}

int	draw_loop(t_mlx *mlx)
{
	process(mlx);
	draw(mlx);
	return (0);
}

void	init_mlx(t_mlx *mlx)
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

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		init_mlx(&mlx);
		if (loadmap(&mlx, argv[1]))
			return (1);
		mlx.mlx_ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Cub3D");
		mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
		mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
				&mlx.img.size_l, &mlx.img.endian);
		mlx_loop_hook(mlx.mlx_ptr, &draw_loop, &mlx);
		mlx_hook(mlx.win, 17, 0, exit_hook, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments", 2);
		return (1);
	}
}
