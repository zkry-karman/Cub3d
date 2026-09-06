/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_master_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:15:11 by karmanz           #+#    #+#             */
/*   Updated: 2026/09/06 16:30:03 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_graphics(t_bible *master)
{
	master->graphics.floor_color = -1;
	master->graphics.ceiling_color = -1;
	master->graphics.no_path = NULL;
	master->graphics.so_path = NULL;
	master->graphics.ea_path = NULL;
	master->graphics.we_path = NULL;
	master->graphics.no_tex.img_ptr = NULL;
	master->graphics.so_tex.img_ptr = NULL;
	master->graphics.ea_tex.img_ptr = NULL;
	master->graphics.we_tex.img_ptr = NULL;
}

void	initialize_player_state(t_bible *master)
{
	master->player.x = -1.0;
	master->player.y = -1.0;
	master->player.dir_x = 0.0;
	master->player.dir_y = 0.0;
	master->player.plane_x = 0.0;
	master->player.plane_y = 0.0;
	master->player.dir = 0;
	master->player.player_count = 0;
}

void	initialize_master(t_bible *master)
{
	ft_memset(master, 0, sizeof(t_bible));
	master->map.grid = NULL;
	master->map.width = 0;
	master->map.height = 0;
	master->map.tile_size = 0;
	master->mlx = NULL;
	master->mlx_win = NULL;
	master->mlx_win = NULL;
	master->img.img_ptr = NULL;
	initialize_minimap_stats(master);
}
