/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:31:20 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/25 21:05:29 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    put_pixel_to_frame(t_img *img, int x, int y, int color)
{
    char    *dest;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dest = color;
}

void    draw_minimap_tile(t_bible *master, int screen_x, int screen_y, int color)
{
    int x;
    int y;

    y = 0;
    while (y < master->map.tile_size)
    {
        x = 0;
        while (x < master->map.tile_size)
        {
            put_pixel_to_frame(&master->img, screen_x + x, screen_y + y, color);
            x++;
        }
        y++;
    }
}

void    update_minimap(t_bible *master)
{
    int map_x;
    int map_y;

    map_y = 0;
    master->map.tile_size = 8;
    while (map_y < master->map.height)
    {
        map_x = 0;
        while (map_x < master->map.width)
        {
            if (master->map.grid[map_y][map_x] == '1')
                draw_minimap_tile(master, map_x * master->map.tile_size, map_y * master->map.tile_size, 0x808080);
            else if (master->map.grid[map_y][map_x] == '0')
                draw_minimap_tile(master, map_x * master->map.tile_size, map_y * master->map.tile_size, 0x000000);
            map_x++;
        }
        map_y++;
    }
    draw_minimap_tile(master, (int)(master->player.x * master->map.tile_size), (int)(master->player.y * master->map.tile_size), 0xFF0000);
}