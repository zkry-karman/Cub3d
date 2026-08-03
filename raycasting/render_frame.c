/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:16:25 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/03 19:11:55 by kzhu@student.42.f###   ########.fr       */
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

void render_frame(t_bible *data)
{
	t_ray ray;
	int		x;
	
	x = 0;
	while (x < WIDTH)
	{
		init_ray_for_column(&data->player, &ray, x);
		init_dda_position(&data->player, &ray);
		printf("column: %d\n", x);
		printf("ray direction: (%f, %f)\n",
			ray.dir_x, ray.dir_y);
		printf("map cell: (%d, %d)\n",
			ray.map_x, ray.map_y);
		printf("step: (%d, %d)\n",
			ray.step_x, ray.step_y);
		x++;
	}
}