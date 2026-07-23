/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:50:30 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/07/23 17:54:14 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_mock_data(t_bible *data)
{
	data->map.width = 5;
	data->map.height = 5;
	data->map.grid = malloc(sizeof(char *) * 5);

	data->map.grid[0] = strdup("11111");
    data->map.grid[1] = strdup("10001");
    data->map.grid[2] = strdup("10001");
    data->map.grid[3] = strdup("10001");
    data->map.grid[4] = strdup("11111");

	data->player.x = 2.5;
    data->player.y = 2.5;
    data->player.dir = 'N';

	data->graphics.ceiling_color = 0x00FF0000;
	data->graphics.floor_color = 0x000000FF;
}