/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:27:18 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/17 11:29:22 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_ray(t_mlx *mlx)
{
	mlx->ray.raydir_x = mlx->player.dir_x + mlx->player.plane_x
		* mlx->ray.camera_x;
	mlx->ray.raydir_y = mlx->player.dir_y + mlx->player.plane_y
		* mlx->ray.camera_x;
	mlx->ray.map_x = (int)mlx->player.pos_x;
	mlx->ray.map_y = (int)mlx->player.pos_y;
	mlx->ray.deltadist_x = fabs(1 / mlx->ray.raydir_x);
	mlx->ray.deltadist_y = fabs(1 / mlx->ray.raydir_y);
}

static void	verline(t_mlx *mlx, int x, int draw_start, int draw_end)
{
	int	y;
	int	color;
	int texNum = mlx->map.map[mlx->ray.map_x][mlx->ray.map_y] -1;
	int line_height;
	double tex_pos;
	double texy;

	line_height = (int)(HEIGHT / mlx->ray.perp_wall_dist);
	if (mlx->ray.side == 1)
		mlx->ray.wallx =  mlx->ray.map_y + mlx->ray.perp_wall_dist * mlx->ray.raydir_y;
	else
		mlx->ray.wallx =  mlx->ray.map_y + mlx->ray.perp_wall_dist * mlx->ray.raydir_x;
	mlx->ray.wallx -= floor(mlx->ray.wallx);
	mlx->ray.texX = (int)(mlx->ray.wallx * (double)texWidth);
	if (mlx->ray.side == 0 && mlx->ray.raydir_x > 0)
		mlx->ray.texX =  texWidth - mlx->ray.texX - 1;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y < 0)
		mlx->ray.texX =  texWidth - mlx->ray.texX - 1;
	mlx->ray.step = 1.0 * texHeight / line_height;
	tex_pos = ((draw_start - 100 - HEIGHT / 2) + line_height /2 ) * mlx->ray.step;
	y = draw_start;
	if (mlx->ray.side == 1)
	while (y <= draw_end)
	{
		texy = tex_pos;
		tex_pos += mlx->ray.step;
		color = 0 + texy * 100;
		mlx->buf[y][x] = color;
		++y;
	}
	if (draw_end < 0)
		draw_end = HEIGHT;
	y = draw_end + 1;
	while (y < HEIGHT)
	{
		mlx->buf[y][x] = get_hex(mlx->map.floor_r, mlx->map.floor_g,
				mlx->map.floor_b);
		mlx->buf[HEIGHT - y][x] = get_hex(mlx->map.ceil_r,
				mlx->map.ceil_g, mlx->map.ceil_b);
		++y;
	}
}

static void	draw_walls(t_mlx *mlx, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
		
	if (mlx->ray.side == 0)
		mlx->ray.perp_wall_dist = mlx->ray.sidedist_x - mlx->ray.deltadist_x;
	else
		mlx->ray.perp_wall_dist = mlx->ray.sidedist_y - mlx->ray.deltadist_y;
	line_height = (int)(HEIGHT / mlx->ray.perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	verline(mlx, x, draw_start, draw_end);
}

void	process(t_mlx *mlx)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		mlx->ray.camera_x = 2 * x / (double)(WIDTH) - 1;
		setup_ray(mlx);
		calc_step(mlx);
		dda(mlx);
		draw_walls(mlx, x);
		++x;
	}
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->img.data[y * WIDTH + x] = mlx->buf[y][x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}
