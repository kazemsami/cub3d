/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:57:43 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:19:11 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_floor_col(t_mlx *mlx, char **strs)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (strs[i])
		++i;
	if (i != 3)
		return (1);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	mlx->map.floor_r = r;
	mlx->map.floor_g = g;
	mlx->map.floor_b = b;
	return (0);
}

int	check_ceiling_col(t_mlx *mlx, char **strs)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (strs[i])
		++i;
	if (i != 3)
		return (1);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	mlx->map.ceil_r = r;
	mlx->map.ceil_g = g;
	mlx->map.ceil_b = b;
	return (0);
}

int	check_color(t_mlx *mlx)
{
	char	**tmp;

	tmp = ft_split(mlx->map.floor_color, ',');
	if (check_floor_col(mlx, tmp))
		return (1);
	free_split(tmp);
	tmp = ft_split(mlx->map.ceiling_color, ',');
	if (check_ceiling_col(mlx, tmp))
		return (1);
	free_split(tmp);
	return (0);
}

int	check_texture(t_mlx *mlx)
{
	int	fd;

	fd = open(mlx->map.e_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(mlx->map.s_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(mlx->map.n_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open(mlx->map.w_texture, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_nonewline(char *file_cont)
{
	int	i;
	int	is_inmap;

	i = 0;
	is_inmap = 0;
	while (file_cont[i])
	{
		if (is_map(&file_cont[i]) == 1 && !is_inmap)
			is_inmap = 1;
		if (is_map(&file_cont[i]) == 2 && is_inmap)
			return (1);
		while (file_cont[i] != '\n' && file_cont[i])
			++i;
		++i;
	}
	return (0);
}
