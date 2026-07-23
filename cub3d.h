/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:17:02 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/23 18:09:25 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <mlx/mlx.h>

# define WIDTH 1080
# define HEIGHT 720

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
}   t_map;

typedef struct s_graphic
{
    int floor_color;
	int ceiling_color;
}   t_graphic;

//for raycasting
typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_player
{
    double	x;
	double	y;
	char	dir;
}   t_player;

typedef struct  s_bible
{
    t_map       map;
    t_player    player;
	t_graphic	graphics;
	t_img		img;
    void        *mlx;
    void        *mlx_win;
}   t_bible;

void init_mock_data(t_bible *data);

#endif