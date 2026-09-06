/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_master_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:15:11 by karmanz           #+#    #+#             */
/*   Updated: 2026/09/06 16:01:49 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_master(t_bible *master)
{
	ft_memset(master, 0, sizeof(t_bible));
	master->graphics.floor_color = -1;
	master->graphics.ceiling_color = -1;
	master->player.x = -1.0;
	master->player.y = -1.0;
	master->player.player_count = 0;
	master->graphics.no_path = NULL;
	master->graphics.so_path = NULL;
	master->graphics.ea_path = NULL;
	master->graphics.we_path = NULL;
	initialize_minimap_stats(master);
}
