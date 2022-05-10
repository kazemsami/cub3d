/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:19 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/09 19:09:57 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	process(t_mlx *mlx)
{
	
}

void	draw_loop(t_mlx *mlx)
{
	process(mlx);
	draw(mlx);
}

int	is_element(t_mlx *mlx, int isnot)
{
	if (isnot)
	{
		if (!mlx->map.ntexture && !mlx->map.stexture
			&& !mlx->map.wtexture && !mlx->map.etexture
			&& !mlx->map.fcolor && !mlx->map.ccolor)
			return (1);
		return (0);
	}
	else
	{
		if (mlx->map.ntexture && mlx->map.stexture
			&& mlx->map.wtexture && mlx->map.etexture
			&& mlx->map.fcolor && mlx->map.ccolor)
			return (1);
		return (0);
	}
}

int	loadmap(t_mlx *mlx, char *file_name)
{
	int		fd;
	int		in_map;
	char	*line;

	in_map = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		while (*line == ' ')
			line++;
		if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
			|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2)
			&& !in_map)
		{
			if (!ft_strncmp(line, "NO ", 3))
			{
				if (mlx->map.stexture || mlx->map.wtexture
					|| mlx->map.etexture || mlx->map.fcolor || mlx->map.ccolor)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				if (!mlx->map.ntexture)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.n_texture = ft_strdup(line);
					mlx->map.ntexture = 1;
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
			else if (!ft_strncmp(line, "SO ", 3))
			{
				if (!mlx->map.ntexture)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				else if (!mlx->map.stexture)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.s_texture = ft_strdup(line);
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
			else if (!ft_strncmp(line, "WE ", 3))
			{
				if (!mlx->map.stexture)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				if (!mlx->map.wtexture)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.w_texture = ft_strdup(line);
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
			else if (!ft_strncmp(line, "EA ", 3))
			{
				if (!mlx->map.wtexture)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				if (!mlx->map.etexture)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.e_texture = ft_strdup(line);
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
			else if (!ft_strncmp(line, "F ", 2))
			{
				if (!mlx->map.etexture)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				if (!mlx->map.fcolor)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.floor_color = ft_strdup(line);
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
			else if (!ft_strncmp(line, "C ", 2))
			{
				if (!mlx->map.fcolor)
				{
					ft_putstr_fd("Error\nElements are not"
						"in the right order.", 2);
					return (1);
				}
				if (!mlx->map.ccolor)
				{
					line += 2;
					while (*line == ' ')
						line++;
					mlx->map.ceiling_color = ft_strdup(line);
				}
				else
				{
					ft_putstr_fd("Error\nDuplicates in map found.", 2);
					return (1);
				}
			}
		}
		else if (in_map && !(isMap(line) && is_element(mlx, 0)
				&& is_element(mlx, 1)))
		{
			ft_putstr_fd("Error\nMap is in the wrong format", 2);
			return (1);
		}
		else if (isMap(line) && is_element(mlx, 0) && is_element(mlx, 1))
		{
			in_map = 1;
		}
		else
		{
			ft_putstr_fd("Error\nInvalid characters in the map", 2);
			return (1);
		}
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		loadmap(&mlx, argv[1]);
		mlx.mlx_ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx_ptr, 800, 600, "Cub3d");
		mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, 800, 600);
		mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
				&mlx.img.size_l, &mlx.img.endian);
		mlx_loop_hook(mlx.mlx_ptr, draw_loop, &mlx);
		draw_loop(&mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments", 2);
		return (1);
	}
}
