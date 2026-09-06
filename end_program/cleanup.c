/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 15:06:07 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/06 16:33:02 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_failure(t_bible *master)
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

void	destory_images(t_bible *data)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->graphics.no_tex.img_ptr)
		mlx_destroy_image(data->mlx, data->graphics.no_tex.img_ptr);
	if (data->graphics.so_tex.img_ptr)
		mlx_destroy_image(data->mlx, data->graphics.so_tex.img_ptr);
	if (data->graphics.ea_tex.img_ptr)
		mlx_destroy_image(data->mlx, data->graphics.ea_tex.img_ptr);
	if (data->graphics.we_tex.img_ptr)
		mlx_destroy_image(data->mlx, data->graphics.we_tex.img_ptr);
}