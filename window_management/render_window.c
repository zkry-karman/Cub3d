/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:50:30 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/20 19:35:59 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_mock_data(t_bible *data)
{
	data->map.width = 5;
	data->map.height = 5;
	data->map.grid = malloc(sizeof(char *) * 5);

	data->map.grid[0] = ft_strdup("11111");
    data->map.grid[1] = ft_strdup("10001");
    data->map.grid[2] = ft_strdup("10001");
    data->map.grid[3] = ft_strdup("10001");
    data->map.grid[4] = ft_strdup("11111");

	data->player.x = 3.5;
    data->player.y = 3.5;
    data->player.dir = 'N';

	data->graphics.ceiling_color = 0x00ADD8E6;
	data->graphics.floor_color = 0x00D3D3D3;
}

void render_background(t_bible *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(&data->img, x, y, data->graphics.ceiling_color);
			else
				my_mlx_pixel_put(&data->img, x, y, data->graphics.floor_color);
			x++;
		}
		y++;
	}
}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;
    int  offset;

    offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
    dst = img->addr + offset;
    
    *(unsigned int *)dst = color;
}

