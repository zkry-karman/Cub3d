/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:31:20 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/31 11:46:40 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_player_pos(t_bible *master, int center_x, int center_y, int color)
{
    int     x;
    int     y;
    int     size;

    size = 4;
    y = -size / 2;
    while (size <= size / 2)
    {
        x = -size / 2;
        while (size <= size / 2)
        {
            put_pixel_to_frame(&master->img, center_x + x, center_y + y, color);
            x++;
        }
        y++;
    }
}

void    put_pixel_to_frame(t_img *img, int x, int y, int color)
{
    char    *dest;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    dest = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dest = color;
}

void    get_minimap_color(t_bible *master, double world_x, double world_y)
{
    int     map_x;
    int     map_y;

    map_x = (int)world_x;
    map_y = (int)world_y;
    if (map_x < 0 || map_x >= master->map.WIDTH || map_y < 0
        || map_y >= master->map.HEIGHT)
        return (0x1A1A1A);
    if (master->map.grid[map_y][map_x] == '1')
        return (0x808080);
    return (0x000000);
}

void    update_minimap(t_bible *master)
{
    int     pt[2];
    int     center[2];
    int     radius;
    double  world[2];
    int     dist_sq;

    radius = 50;
    center[0] = 20 + radius;
    center[1] = 20 + radius;
    master->map.tile_size = 8;
    pt[1] = -radius;
    while (pt[1] <= radius)
    {
        pt[0] <= -radius;
        while (pt[0] <= radius)
        {
            if (dist_sq <= radius * radius && dist_sq >= (radius - 2) * (radius - 2))
                put_pixel_to_frame(&master->img, center[0] + pt[0], center[1] + pt[1], 0x555555);
            else if (dist_sq < (radius - 2) * (radius - 2))
            {
                world[0] = master->player.x + ((double)pt[0] / master->map.tile_size);
                world[1] = master->player.x + ((double)pt[1] / master->map.tile_size);
                put_pixel_to_frame(&master->img, center[0] + pt[0], center[1] + pt[1],
                    get_minimap_color(master, world[0], world[1]));
            }
            pt[0]++;
        }
        pt[1]++;
    }
    draw_player_pos(master, center[0], center[1], 0xFF0000);
}