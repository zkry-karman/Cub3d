/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:17:02 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/10 19:30:24 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define WIDTH 200
# define HEIGHT 720
# define ESC 65307

# define PLANE_LENGTH 0.66

typedef struct s_line
{
    char    *line;
    struct s_line *next;
}   t_line;

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
}   t_map;

typedef struct s_graphic
{
    char    *no_path;
    char    *ea_path;
    char    *so_path;
    char    *we_path;
    int     floor_color;
	int     ceiling_color;
}   t_graphic;

//for raycasting
typedef struct s_img
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_ray
{
	double 	camera_x;
	double 	dir_x;
	double 	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		wall_flag;
	int		wall_type;
}	t_ray;


typedef struct s_player
{
    double	x;
	double	y;
	double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
	char	dir; //initial spawn orientation
    int     player_count;
}   t_player;

typedef struct  s_bible
{
    t_map       *map;
    t_player    player;
	t_graphic	graphics;
	t_img		img;
    void        *mlx;
    void        *mlx_win;
}   t_bible;

void init_mock_data(t_bible *data);
int key_press(int key, t_bible *data);
int close_window(t_bible *data);

void render_background(t_bible *data);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);

int 	init_player_direction(t_player *player);
void 	init_camera_plane(t_player *player);

void 	render_rays(t_bible *data);
void 	init_ray_for_column(t_player *player, t_ray *ray, int x);
void 	init_delta_dist(t_ray *ray);
void	init_dda_position(t_player *player, t_ray *ray);
void	init_side_dist(t_player *player, t_ray *ray);

void	run_dda(t_ray *ray, char **map);

#endif