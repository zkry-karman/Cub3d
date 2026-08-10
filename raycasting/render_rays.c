/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:16:25 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/10 19:30:31 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray_for_column(t_player *player, t_ray *ray, int x)
{
	
	ray->camera_x = 2 * (x / (double) WIDTH) - 1;
	ray->dir_x = player->dir_x + (player->plane_x * ray->camera_x );
	ray->dir_y = player->dir_y + (player->plane_y * ray->camera_x );
}

void init_dda_position(t_player *player, t_ray *ray)
{
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	if (ray->dir_x < 0)
		ray->step_x = -1;
	else if (ray->dir_x > 0)
		ray->step_x = 1;
	else
		ray->step_x = 0;
	if (ray->dir_y < 0)
		ray->step_y = -1;
	else if (ray->dir_y > 0)
		ray->step_y = 1;
	else
		ray->step_y = 0;
}

void init_delta_dist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->dir_y);
}

void init_side_dist(t_player *player, t_ray *ray)
{
	if (ray->step_x > 0)
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	else if (ray->step_x < 0)
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = 1e30;
	if (ray->step_y > 0)
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	else if (ray->step_y < 0)
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = 1e30;
}

void render_rays(t_bible *data)
{
	t_ray ray;
	int		x;
	
	x = 0;
	while (x < WIDTH)
	{
		init_ray_for_column(&data->player, &ray, x);
		init_dda_position(&data->player, &ray);
		init_delta_dist(&ray);
		run_dda(&ray, data->map->grid);
		x++;
	}
}