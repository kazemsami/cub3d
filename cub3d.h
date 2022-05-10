/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabusitt <kabusitt@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:46:10 by kabusitt          #+#    #+#             */
/*   Updated: 2022/05/09 18:23:48 by kabusitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_img {
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_map {
	char	*map;
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
}	t_map;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win;
	t_img	img;
	t_map	map;
}	t_mlx;

#endif