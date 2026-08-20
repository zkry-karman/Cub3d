/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:16:13 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/20 21:54:22 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void run_dda(t_ray *ray, char **map)
{
	ray->wall_flag = 0;
	while (ray->wall_flag == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->wall_type = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->wall_type = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
		{
			if (ray->wall_type == 0)
				ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
			else
				ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
			ray->wall_flag = 1;
		}
	}
}

void draw_line(t_ray *ray, t_bible *data, int x)
{
	int line_height;
	int draw_start;
	int draw_end;
	int wall_top;
	int tex_y; // 0 - 63 if the tile size is 64, but essentially this is just 100% scale
	int color;
	int y;

	line_height = HEIGHT / ray->wall_dist;
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	wall_top = draw_start;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = draw_start;
	while (y <= draw_end)
	{
		tex_y = (int)(((double)(y - wall_top) / line_height) * data->graphics.wall_tex.height);
		if (tex_y >= data->graphics.wall_tex.height)
			tex_y = data->graphics.wall_tex.height - 1;
		color = get_texture_pixel(&data->graphics.wall_tex, ray->tex_x, tex_y);
		my_mlx_pixel_put(&data->img, x, y, color);
		y++;
	}
}

void wall_hit(t_ray *ray, t_bible *data)
{
	if (ray->wall_type == 0)
		ray->wall_hit = data->player.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = data->player.x + ray->wall_dist * ray->dir_x;
	ray->wall_hit -= floor(ray->wall_hit);
	ray->tex_x = (int)(ray->wall_hit * data->graphics.wall_tex.width);
}