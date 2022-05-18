/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:29:45 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/18 18:28:27 by kabusitt         ###   ########.fr       */
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

static int	find_colour(t_mlx *mlx, int texy)
{
	if (mlx->ray.raydir_y < 0)
	{
		if (mlx->ray.side == 1)
			return (mlx->img[EA].data[64 * texy + mlx->ray.tex_x]);
		else if (mlx->ray.raydir_x > 0)
			return (mlx->img[NO].data[64 * texy + mlx->ray.tex_x]);
		else
			return (mlx->img[SO].data[64 * texy + mlx->ray.tex_x]);
	}
	if (mlx->ray.raydir_y >= 0)
	{
		if (mlx->ray.side == 1)
			return (mlx->img[WE].data[64 * texy + mlx->ray.tex_x]);
		else if (mlx->ray.raydir_x > 0)
			return (mlx->img[NO].data[64 * texy + mlx->ray.tex_x]);
		else
			return (mlx->img[SO].data[64 * texy + mlx->ray.tex_x]);
	}
	return (0);
}

void	draw_texture(t_mlx *mlx, int x, int draw_start, int draw_end)
{
	int		texy;
	int		y;
	int		color;
	double	tex_pos;
	int		line_height;

	line_height = (int)(HEIGHT / mlx->ray.perp_wall_dist);
	mlx->ray.wallx -= floor((mlx->ray.wallx));
	mlx->ray.tex_x = (int)(mlx->ray.wallx * (double)64);
	if (mlx->ray.side == 0 && mlx->ray.raydir_x > 0)
		mlx->ray.tex_x = 64 - mlx->ray.tex_x - 1;
	if (mlx->ray.side == 1 && mlx->ray.raydir_y < 0)
		mlx->ray.tex_x = 64 - mlx->ray.tex_x - 1;
	mlx->ray.step = 1.0 * 64 / line_height;
	tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * mlx->ray.step;
	y = draw_start;
	while (y < draw_end)
	{
		texy = (int)tex_pos & (64 - 1);
		tex_pos += mlx->ray.step;
		color = find_colour(mlx, texy);
		mlx->buf[y][x] = color;
		y++;
	}
}
