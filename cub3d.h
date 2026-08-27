/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:17:02 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/27 21:09:00 by kzhu@student.42.f###   ########.fr       */
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
# include <fcntl.h>
# include <unistd.h>
# include "GNL/get_next_line.h"

# define WIDTH 1080
# define HEIGHT 720
# define ESC 65307
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define PLANE_LENGTH 0.66

# define TEX_WIDTH 64

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define MOUSE_SPEED 0.00025

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
	int		tile_size;
}   t_map;

//for raycasting
typedef struct s_img
{
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	int		width;
	int		height;
}   t_img;

typedef struct s_graphic
{
    char    *no_path;
    char    *ea_path;
    char    *so_path;
    char    *we_path;
	t_img	no_tex;
	t_img	so_tex;
	t_img	we_tex;
	t_img	ea_tex;
    int     floor_color;
	int     ceiling_color;
}   t_graphic;

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
	double	wall_dist;
	double	wall_hit;
	int		tex_x;
	int		wall_flag;
	int		wall_type;
}	t_ray;

typedef struct s_wall_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	wall_top;
	int x;
}	t_wall_draw;

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
    t_map       map;
    t_player    player;
	t_graphic	graphics;
	t_img		img;
    void        *mlx;
    void        *mlx_win;
}   t_bible;

void engine(t_bible *master);

void    		initialize_master(t_bible *master);
int 			parse_cub_file(t_bible *master, char *file_path);
void    		parsing_failure(t_bible *master);
int				parse_textures(t_bible *master, char *line);
int 			parse_rgb(t_bible *master, char *line);
int				parse_map(t_bible *master, char *head, int fd);
int				check_xpm_files(t_bible *master);
int				check_dup_rgb(t_bible *master, char *line);
char    		*skip_whitespace(char *line);
int				check_other_configs(t_bible *master);
int				scan_copy_line(t_bible *master, t_line *curr, int x, int y);
int				pad_empty_spaces(t_bible *master, int x, int y);
t_line			*initialize_map_dimensions(t_bible *master, char *head);
int				ft_strlen_cub3d(char *str);
void			ft_add_new_node(t_line **list, char *line);
char			**duplicate_map(char **og_map, int height);
void			free_double_pointer(char **arr);
void			ft_lstclear_cub3d(t_line **lst, void (*del)(void *));
char			*trim_backend(char *str);
int				parse_textures(t_bible *master, char *line);
int				check_dup_no(t_bible *master);
int				check_dup_so(t_bible *master);
int				check_dup_ea(t_bible *master);
int				check_dup_we(t_bible *master);
void			store_player_pos(t_bible *master, int x, int y, char direction);
void    		update_minimap(t_bible *master);

int				key_press(int key, t_bible *data);
int				close_window(t_bible *data);

void			render_background(t_bible *data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			render_frame(t_bible *data);

void 			init_player_direction(t_player *player);
void 			init_camera_plane(t_player *player);

void 			render_rays(t_bible *data);
void 			init_ray_for_column(t_player *player, t_ray *ray, int x);
void 			init_delta_dist(t_ray *ray);
void			init_dda_position(t_player *player, t_ray *ray);
void			init_side_dist(t_player *player, t_ray *ray);

void 			run_dda(t_ray *ray, char **map);
void			draw_line(t_ray *ray, t_bible *data, int x, t_img *tex);
void			draw_tex(t_ray *ray, t_bible *data, t_img *tex, t_wall_draw *draw);
void			wall_hit(t_ray *ray, t_bible *data, t_img *tex);

int				load_texture(t_bible *data, t_img *tex, char *path);
int 			load_all_textures(t_bible *master);
unsigned int	get_texture_pixel(t_img *tex, int x, int y);
t_img			*get_wall_texture(t_ray *ray, t_graphic *graphic);

int 			move_hook(int keycode, t_bible *data);
void 			move_player_ws(t_player *player, t_map *map, double amount);
void 			move_player_ad(t_player *player, t_map *map, double amount);
int				mouse_move(int x, int y, t_bible *data);
void			rotate_player(t_player *player, double angle);
int				mouse_enter(t_bible *data);
int				mouse_leave(t_bible *data);

#endif