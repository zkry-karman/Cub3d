/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:31:20 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/23 15:44:21 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_minimap_tile(t_bible *master, int screen_x, int screen_y)

void    update_minimap(t_bible *master)
{
    int map_x;
    int map_y;
    int tile_size;

    map_y = 0;
    tile_size = 8;
    while (map_y < master->map.height)
    {
        map_x = 0;
        while (map < master->map.width)
        {
            if (master->map.grid[map_y][map_x] == '1')
                draw_minimap_tile(master, map_x * tile_size, map_y * tile_size, tile_size, 0x808080);
            else if (master->map.grid[map_y][map_x] == '0')
                draw_minimap_tile(master, map_x * tile_size, map_y * tile_size, tile_size, 0x000000);
            map_x++;
        }
        map_y++;
    }
    draw_minimap_tile(master, (int)(master->player.x * tile_size), (int)(master->player.y * tile_size), 4, 0xFF0000);
}