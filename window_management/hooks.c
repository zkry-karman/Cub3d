/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:26:25 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/07/24 14:31:44 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int close_window(t_bible *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    // Note: Later, you will need to free your malloc'd map here before exiting!
    exit(0);
    return (0);
}

int key_press(int key, t_bible *data)
{
    if (key == ESC)
        close_window(data);
    return (0);
}