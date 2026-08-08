/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:02:35 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/08 16:36:10 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line    *intialize_map_dimensions(t_bible *master, char *head, t_line *lines)
{
    t_line  *lines;
    
    lines = ft_add_line_node(&lines, head);
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