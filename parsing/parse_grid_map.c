/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:43:21 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/27 21:26:53 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int pad_copy_map(t_bible *master, t_line *line_list)
{
    int x;
    int y;
    int line_len;
    t_line  *curr;

    master->map.grid = malloc(sizeof(char *) * (master->map.height + 1))
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

    lines = ft_add_line_node(&lines, head);
    while ((line = get_next_line(fd)))
    {
        if (master->map.width == 0 || master->map.width < ft_strlen_cub3d(line))
            master->map.width == ft_strlen_cub3d(line);
        ft_add_new_node(&lines, line);
        master->map.height++;
        free(line);
    }
    if (!pad_copy_map(master, lines))
    {
        return (0);   
    }
}