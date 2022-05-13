/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:10 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/13 17:45:11 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_img {
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_player {
	int	pos_x;
	int	pos_y;
	int	dir_y;
	int	dir_x;
	int	plane_x;
	int	plane_y;
}	t_player;

typedef struct s_map {
	char	**map;
	char	*floor_color;
	char	*ceiling_color;
	char	*w_texture;
	char	*n_texture;
	char	*e_texture;
	char	*s_texture;
	int		wtexture;
	int		ntexture;
	int		stexture;
	int		etexture;
	int		fcolor;
	int		ccolor;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
	int		max;
	int		size;
}	t_map;

typedef struct s_mlx {
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}	t_mlx;

int		check_map(t_mlx *mlx);
int		out_of_bounds(char **map, int i, int z);
int		check_ifone_h(t_mlx *mlx, int i, int z);
int		check_ifone_v(t_mlx *mlx, int i, int z);
int		check_closed(t_mlx *mlx);
void	free_split(char **strs);
void	free_mem(t_mlx *mlx);
int		exit_hook(t_mlx *mlx);
int		validate_map(t_mlx *mlx, char **strs);
int		iselement(char *str);
int		parse_map(t_mlx *mlx, char **strs);
int		loadmap(t_mlx *mlx, char *file_name);
int		check_ccolor(t_mlx *mlx, char *str);
int		check_c_and_f(t_mlx *mlx, char *str);
int		check_elements(t_mlx *mlx, char *str);
int		malloc_map(t_mlx *mlx, char **strs);
char	*read_file(int fd);
int		check_south(t_mlx *mlx, char *str);
int		check_north(t_mlx *mlx, char *str);
int		check_west(t_mlx *mlx, char *str);
int		check_east(t_mlx *mlx, char *str);
int		check_fcolor(t_mlx *mlx, char *str);
int		check_floor_col(t_mlx *mlx, char **strs);
int		check_ceiling_col(t_mlx *mlx, char **strs);
int		check_color(t_mlx *mlx);
int		check_texture(t_mlx *mlx);
int		check_nonewline(char *file_cont);
int		elements_exist(t_mlx *mlx, int isnot);
int		is_map(char *str);
int		cpy_map(t_mlx *mlx, char **strs, int max);
int		find_max(char **strs);
int		check_filecont(char *file_cont);

#endif