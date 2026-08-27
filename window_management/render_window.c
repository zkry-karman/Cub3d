/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:50:30 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/27 15:15:28 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	render_frame(t_bible *data)
{
	render_background(data);
	render_rays(data);
	update_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
}

