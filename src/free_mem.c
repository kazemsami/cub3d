/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:29:31 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/19 13:11:42 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_mem(t_mlx *mlx)
{
	free_split(mlx->map.map);
	free(mlx->map.ceiling_color);
	free(mlx->map.e_texture);
	free(mlx->map.n_texture);
	free(mlx->map.s_texture);
	free(mlx->map.floor_color);
	free(mlx->map.w_texture);
}

void	free_map(t_mlx *mlx)
{
	if (mlx->map.map != NULL)
		free_split(mlx->map.map);
	if (mlx->map.ccolor)
		free(mlx->map.ceiling_color);
	if (mlx->map.fcolor)
		free(mlx->map.floor_color);
	if (mlx->map.wtexture)
		free(mlx->map.w_texture);
	if (mlx->map.stexture)
		free(mlx->map.s_texture);
	if (mlx->map.etexture)
		free(mlx->map.e_texture);
	if (mlx->map.ntexture)
		free(mlx->map.n_texture);
}

int	exit_hook(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[0].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[1].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[2].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[3].img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img[4].img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	free_mem(mlx);
	exit(0);
}
