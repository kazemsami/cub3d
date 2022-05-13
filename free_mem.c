/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:29:31 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:07:01 by kabusitt         ###   ########.fr       */
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

int	exit_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	free_mem(mlx);
	exit(0);
}
