/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:16:13 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/31 12:17:01 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_dda(t_ray *ray, char **map)
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

void	draw_tex(t_ray *ray, t_bible *data, t_img *tex, t_wall_draw *draw)
{
	int	y;
	int	tex_y;
	int	color;

	y = draw->draw_start;
	while (y <= draw->draw_end)
	{
		tex_y = (int)(((double)(y - draw->wall_top) / draw->line_height)
				* tex->height);
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = get_texture_pixel(tex, ray->tex_x, tex_y);
		my_mlx_pixel_put(&data->img, draw->x, y, color);
		y++;
	}
}

void	draw_line(t_ray *ray, t_bible *data, int x, t_img *tex)
{
	t_wall_draw	draw;

	draw.x = x;
	draw.line_height = HEIGHT / ray->wall_dist;
	draw.draw_start = -draw.line_height / 2 + HEIGHT / 2;
	draw.draw_end = draw.line_height / 2 + HEIGHT / 2;
	draw.wall_top = draw.draw_start;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	if (draw.draw_end >= HEIGHT)
		draw.draw_end = HEIGHT - 1;
	draw_tex(ray, data, tex, &draw);
}

void	wall_hit(t_ray *ray, t_bible *data, t_img *tex)
{
	if (ray->wall_type == 0)
		ray->wall_hit = data->player.y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_hit = data->player.x + ray->wall_dist * ray->dir_x;
	ray->wall_hit -= floor(ray->wall_hit);
	ray->tex_x = (int)(ray->wall_hit * tex->width);
}
