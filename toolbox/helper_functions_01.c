/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:02:35 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/25 16:13:26 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    check_for_player_pos(t_bible *master, t_line *curr, int x, int y)
{
    if (curr->line[x] == 'N' || curr->line[x] == 'S' || curr->line[x] == 'E' || curr->line[x] == 'W')           
        store_player_pos(master, x, y, curr->line[x]);
    else
        master->map.grid[y][x] = curr->line[x];

}

int    scan_copy_line(t_bible *master, t_line *curr, int x, int y)
{
    int line_len;

    line_len = ft_strlen(curr->line);
    while (x < line_len)
    {
        check_for_player_pos(master, curr, x, y);
        x++;
    }
    return (x);
}

int    pad_empty_spaces(t_bible *master, int x, int y)
{
    while (x < master->map.width)
    {
        master->map.grid[y][x] = ' ';
        x++;
    }
    return (x);
}

t_line    *initialize_map_dimensions(t_bible *master, char *head)
{
    t_line  *lines;
    
    lines = NULL;
    ft_add_new_node(&lines, head);
    master->map.height = 1;
    master->map.width = ft_strlen_cub3d(head);
    return (lines);
}

int check_other_configs(t_bible *master)
{
    if (!master->graphics.no_path || !master->graphics.ea_path || !master->graphics.so_path || !master->graphics.we_path || master->graphics.floor_color == -1 || master->graphics.ceiling_color == -1)
        return (0);
    return (1);
}