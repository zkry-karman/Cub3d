/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:51:23 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/02 20:55:39 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_player_direction(t_player *player)
{
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	if (player->dir == 'N')
		player->dir_y = -1.0;
	else if (player->dir == 'S')
		player->dir_y = 1.0;
	else if (player->dir == 'W')
		player->dir_y = -1.0;
	else if (player->dir == 'E')
		player->dir_y = 1.0;
	else
		return (0);
	return (1);
}

void init_camera_plane(t_player *player)
{
	if (player->dir == 'N')
	{
		player->plane_x = PLANE_LENGTH;
		player->plane_y = 0.0;
	}
	else if (player->dir == 'S')
	{
		player->plane_x = -PLANE_LENGTH;
		player->plane_y = 0.0;
	}
	else if (player->dir == 'E')
	{
		player->plane_x = 0.0;
		player->plane_y = PLANE_LENGTH;
	}
	else if (player->dir == 'W')
	{
		player->plane_x = 0.0;
		player->plane_y = -PLANE_LENGTH;
	}
}