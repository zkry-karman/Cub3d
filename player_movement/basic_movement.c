/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:38:57 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/22 17:10:12 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_player_WS(t_player *player, t_map *map, float amount)
{
	double new_x;
	double new_y;
	char target_cell;
	
	new_x = player->x + player->dir_x * amount;
	new_y = player->y + player->dir_y * amount;
	target_cell = map->grid[(int)new_y][(int)new_x];
	if (target_cell == '1')
		return ;
	player->x = new_x;
	player->y = new_y;
}

int move_hook(int keycode, t_bible *data)
{
	if (keycode == KEY_W)
		move_player(&data->player, &data->map, MOVE_SPEED);
	else if (keycode == KEY_S)
		move_player(&data->player, &data->map, -MOVE_SPEED);
	else
		return (0);
	render_frame(data);
	return (0);
}