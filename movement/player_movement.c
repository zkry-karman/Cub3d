/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:38:57 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/24 14:47:32 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, double angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void move_player_WS(t_player *player, t_map *map, double amount)
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

void move_player_AD(t_player *player, t_map *map, double amount)
{
	double new_x;
	double new_y;
	char target_cell;
	
	new_x = player->x + (-player->dir_y) * amount;
	new_y = player->y + player->dir_x * amount;
	target_cell = map->grid[(int)new_y][(int)new_x];
	if (target_cell == '1')
		return ;
	player->x = new_x;
	player->y = new_y;
}

int move_hook(int keycode, t_bible *data)
{
	if (keycode == KEY_W)
		move_player_WS(&data->player, &data->map, MOVE_SPEED);
	else if (keycode == KEY_S)
		move_player_WS(&data->player, &data->map, -MOVE_SPEED);
	else if (keycode == KEY_A)
		move_player_AD(&data->player, &data->map, -MOVE_SPEED);
	else if (keycode == KEY_D)
		move_player_AD(&data->player, &data->map, MOVE_SPEED);
	else if (keycode == KEY_LEFT)
		rotate_player(&data->player, -ROT_SPEED);
	else if (keycode == KEY_RIGHT)
		rotate_player(&data->player, ROT_SPEED);
	else
		return (0);
	render_frame(data);
	return (0);
}