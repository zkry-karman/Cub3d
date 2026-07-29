/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:43:21 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/29 13:47:23 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_characters(t_bible *master)
{
    int x;
    int y;

    if (master->player.player_count != 1)
        return (printf("Error\nMust have 1 player"), 0);
    y = 0;
    while (y < master->map.height)
    {
        x = 0;
        while (x < master->map.width)
        {
            if (master->map.grid[y][x] != '1' && master->map.grid[y][x] != '0' && master->map.grid[y][x] != ' ')
                return (printf("Error\nInvalid character in map"), 0);
            x++;
        }
        y++;
    }
    return (1);
}

void store_player_pos(t_bible *master, int x, int y, char direction)
{
    master->player.x = x + 0.5;
    master->player.y = y + 0.5;
    master->player.dir = direction;
}

int pad_copy_map(t_bible *master, t_line *line_list)
{
    int x;
    int y;
    int line_len;
    t_line  *curr;

    master->map.grid = malloc(sizeof(char *) * (master->map.height + 1));
    if (!master->map.grid)
        return (0);
    y = 0;
    curr = line_list;
    while (curr)
    {
        master->map.grid[y] = malloc(sizeof(char) * (master->map.width + 1));
        if (!master->map.grid[y])
            return (0);
        line_len = ft_strlen(curr->line);
        x = 0;
        while (x < line_len)
        {
            if (curr->line[x] == 'N' || curr->line[x] == 'S' || curr->line[x] == 'E' || curr->line[x] == 'W')
            {
                store_player_pos(master, x, y, curr->line[x]);
                master->map.grid[y][x] = '0';
                master->player.player_count++;
            }
            else
                master->map.grid[y][x] = curr->line[x];
            x++;
        }
        while (x < master->map.width)
        {
            master->map.grid[y][x] = ' ';
            x++;
        }
        master->map.grid[y][x] = '\0';
        curr = curr->next;
        y++;
    }
    master->map.grid[y] = NULL;
    return (1);
}

int parse_map(t_bible *master, char *head, int fd)
{
    t_line  *lines;
    char    *line;
    char    **map_copy;

    lines = ft_add_line_node(&lines, head);
    master->map.height = 1;
    master->map.width = ft_strlen_cub3d(head);
    while ((line = get_next_line(fd)))
    {
        if (master->map.width == 0 || master->map.width < ft_strlen_cub3d(line))
            master->map.width = ft_strlen_cub3d(line);
        ft_add_new_node(&lines, line);
        master->map.height++;
        free(line);
    }
    if (!pad_copy_map(master, lines))
        return (ft_lstclear(&lines, free), 0);   
    free_list(&lines, free);
    if (!check_characters(master))
        return (0);
    map_copy = duplicate_map(master->map.grid, master->map.height);
    if (!map_copy)
        return (0);
    if (!flood_fill(map_copy, (int)master->player.y, (int)master->player.x))
    {
        printf("Error\nMap is not fully enclosed\n");
        free_double_pointer(map_copy);
        return (0);
    }
    free_double_pointer(map_copy);
    return (1);
    
}