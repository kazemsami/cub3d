/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:01:57 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/18 13:07:55 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_south(t_mlx *mlx, char *str)
{
	if (!mlx->map.stexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.s_texture = ft_strdup(str);
		mlx->img[SO].img_ptr = mlx_xpm_file_to_image(mlx, mlx->map.s_texture, &mlx->img[SO].width, &mlx->img[SO].hieght);
		mlx->img[SO].data = (int *)mlx_get_data_addr(mlx->img[SO].img_ptr, &mlx->img[SO].bpp, &mlx->img[SO].size_l, &mlx->img[SO].endian);
		mlx->map.stexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_north(t_mlx *mlx, char *str)
{
	if (!mlx->map.ntexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.n_texture = ft_strdup(str);
		printf("string %s\n", str);
		mlx->img[NO].img_ptr = mlx_xpm_file_to_image(mlx, mlx->map.n_texture, &mlx->img[NO].width, &mlx->img[NO].hieght);
		mlx->img[NO].data = (int *)mlx_get_data_addr(mlx->img[NO].img_ptr, &mlx->img[NO].bpp, &mlx->img[NO].size_l, &mlx->img[NO].endian);
		mlx->map.ntexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_west(t_mlx *mlx, char *str)
{
	if (!mlx->map.wtexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.w_texture = ft_strdup(str);
		mlx->img[WE].img_ptr = mlx_xpm_file_to_image(mlx, mlx->map.w_texture, &mlx->img[WE].width, &mlx->img[WE].hieght);
		mlx->img[WE].data = (int *)mlx_get_data_addr(mlx->img[WE].img_ptr, &mlx->img[WE].bpp, &mlx->img[WE].size_l, &mlx->img[WE].endian);
		mlx->map.wtexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_east(t_mlx *mlx, char *str)
{
	if (!mlx->map.etexture)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.e_texture = ft_strdup(str);
		mlx->img[EA].img_ptr = mlx_xpm_file_to_image(mlx, mlx->map.e_texture, &mlx->img[EA].width, &mlx->img[EA].hieght);
		mlx->img[EA].data = (int *)mlx_get_data_addr(mlx->img[EA].img_ptr, &mlx->img[EA].bpp, &mlx->img[EA].size_l, &mlx->img[EA].endian);
		mlx->map.etexture = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_fcolor(t_mlx *mlx, char *str)
{
	if (!mlx->map.fcolor)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.floor_color = ft_strdup(str);
		mlx->map.fcolor = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}
