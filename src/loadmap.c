/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:53:37 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/19 19:28:29 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(t_mlx *mlx, char **strs)
{
	if (malloc_map(mlx, strs))
	{
		ft_putstr_fd("Error\nFailed to initialize map.\n", 2);
		return (1);
	}
	if (check_map(mlx))
	{
		ft_putstr_fd("Error\nMap is not in correct format.\n", 2);
		return (1);
	}
	return (0);
}

int	iselement(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
		|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (1);
	return (0);
}

int	parse_map(t_mlx *mlx, char **strs)
{
	int	i;
	int	chk;

	while (*strs)
	{
		i = 0;
		while ((*strs)[i] == ' ' && !is_map(*strs))
			i++;
		chk = do_map(mlx, strs, i);
		if (chk == 2)
			break ;
		else if (chk == 1)
			return (1);
		strs++;
	}
	return (0);
}

static int	check_map_valid(t_mlx *mlx)
{
	if (mlx->map.map == NULL)
	{
		ft_putstr_fd("Error\nFailed to initialize map.\n", 2);
		return (1);
	}
	if (check_color(mlx))
	{
		ft_putstr_fd("Error\nOne of the RGB color values are wrong.\n", 2);
		return (1);
	}
	return (0);
}

int	loadmap(t_mlx *mlx, char *file_name)
{
	int		fd;
	char	*file_cont;
	char	**strs;

	if (ft_strlen(file_name) < 5
		|| ft_strncmp(file_name + (ft_strlen(file_name) - 4), ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nMap file does not have .cub extension\n", 2);
		return (1);
	}
	fd = open(file_name, O_RDONLY);
	file_cont = read_file(fd);
	if (check_filecont(file_cont))
		return (1);
	strs = ft_split(file_cont, '\n');
	free(file_cont);
	if (parse_map(mlx, strs))
	{
		free_split(strs);
		return (1);
	}
	free_split(strs);
	if (check_map_valid(mlx))
		return (1);
	return (0);
}
