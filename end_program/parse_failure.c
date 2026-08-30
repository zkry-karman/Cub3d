/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_failure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:06:07 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/30 15:32:00 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    parsing_failure(t_bible *master)
{
    if (!master)
        return ;
    if (master->graphics.no_path)
        free(master->graphics.no_path);
    if (master->graphics.so_path)
        free(master->graphics.so_path);
    if (master->graphics.ea_path)
        free(master->graphics.ea_path);
    if (master->graphics.we_path)
        free(master->graphics.we_path);
    if (master->map.grid)
        free_double_pointer(master->map.grid);
}