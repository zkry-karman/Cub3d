/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_master_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:15:11 by karmanz           #+#    #+#             */
/*   Updated: 2026/07/23 21:44:07 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_master(t_bible *master)
{
    ft_memset(master, 0, sizeof(t_bible));
    master->graphics.floor_color = -1;
    master->graphics.ceiling_color = -1;
    master->player.x = -1.0;
    master->player.y = -1.0;
}