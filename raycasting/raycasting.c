/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:16:13 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/15 18:17:02 by kzhu@student.42.f###   ########.fr       */
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
	int y;

	line_height = HEIGHT / ray->wall_dist;
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = draw_start;
	while (y <= draw_end)
	{
		if (ray->wall_type == 0)
			my_mlx_pixel_put(&data->img, x, y, 0xFF0000);
		else
			my_mlx_pixel_put(&data->img, x, y, 0x008000);
		y++;
	}
}

void wall_hit(t_ray *ray, t_bible *data)
{
	if (ray->wall_type == 0)
		ray->wall_hit = data->player.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = data->player.x + ray->wall_dist * ray->dir_x;
}