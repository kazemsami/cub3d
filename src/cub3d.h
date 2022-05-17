/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:10 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/17 11:10:14 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIDTH 852
# define HEIGHT 480
#define texWidth 32
#define texHeight 32

/* Linux Keys */
# define KEY_RIGHT 0xFF53
# define KEY_LEFT 0xFF51
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64
# define DOORS 0x65 // E
# define KEY_ESC 0xFF1B

/* MAC Keys 
# define KEY_A 0x00
# define KEY_S 0x01
# define KEY_D 0x02
# define KEY_W 0x0D
# define KEY_ESC 0x35
# define KEY_LEFT 0x7B
# define KEY_RIGHT 0x7C
*/
typedef struct s_img {
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_y;
	double	dir_x;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray {
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double wallx;
	double texX;
	double step;
}	t_ray;

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
	int			buf[HEIGHT][WIDTH];
	int			key_a;
	int			key_d;
	int			key_s;
	int			key_w;
	int			key_right;
	int			key_left;
	t_img		img;
	t_map		map;
	t_player	player;
	t_ray		ray;
}	t_mlx;

int		check_map(t_mlx *mlx);
int		out_of_bounds(t_mlx *mlx, char **map, int i, int z);
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
int		elements_exist(t_mlx *mlx);
int		is_map(char *str);
int		cpy_map(t_mlx *mlx, char **strs, int max);
int		find_max(char **strs);
int		check_filecont(char *file_cont);
void	free_map(t_mlx *mlx);
int		key_press(int keycode, t_mlx *mlx);
int		key_release(int keycode, t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	turn_right(t_mlx *mlx);
void	turn_left(t_mlx *mlx);
void	init_player(t_mlx *mlx);
void	key_function(t_mlx *mlx);
int		get_hex(int r, int g, int b);
void	calc_step(t_mlx *mlx);
void	dda(t_mlx *mlx);
void	draw(t_mlx *mlx);
void	process(t_mlx *mlx);

#endif