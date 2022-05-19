/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:54:45 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/19 13:13:08 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ccolor(t_mlx *mlx, char *str)
{
	if (!mlx->map.ccolor)
	{
		str += 2;
		while (*str == ' ')
			str++;
		mlx->map.ceiling_color = ft_strdup(str);
		mlx->map.ccolor = 1;
	}
	else
	{
		ft_putstr_fd("Error\nDuplicates found.\n", 2);
		return (1);
	}
	return (0);
}

int	check_c_and_f(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "F ", 2))
	{
		if (check_fcolor(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		if (check_ccolor(mlx, str))
			return (1);
	}
	return (0);
}

int	check_elements(t_mlx *mlx, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (check_north(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		if (check_south(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "WE ", 3))
	{
		if (check_west(mlx, str))
			return (1);
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		if (check_east(mlx, str))
			return (1);
	}
	else if (check_c_and_f(mlx, str))
		return (1);
	return (0);
}

int	malloc_map(t_mlx *mlx, char **strs)
{
	int	i;
	int	max;

	i = 0;
	while (strs[i])
		++i;
	mlx->map.size = i;
	mlx->map.map = malloc(sizeof(char *) * (i + 1));
	if (!mlx->map.map)
		return (1);
	max = find_max(strs);
	mlx->map.max = max;
	i = 0;
	while (strs[i])
	{
		mlx->map.map[i] = malloc(sizeof(char) * (max + 1));
		if (!mlx->map.map[i])
			return (1);
		++i;
	}
	mlx->map.map[i] = 0;
	if (cpy_map(mlx, strs, max))
		return (1);
	return (0);
}

char	*read_file(int fd)
{
	char	*str;
	char	*buffer;
	int		bytes;

	str = NULL;
	buffer = malloc(sizeof(char) * 101);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, 100);
	while (bytes != 0 && bytes != -1)
	{
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		bytes = read(fd, buffer, 100);
	}
	free(buffer);
	return (str);
}
