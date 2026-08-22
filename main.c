/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/22 16:22:19 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_bible data = {0};
	
	init_mock_data(&data);
	if (!init_player_direction(&data.player))
		return (1);
	init_camera_plane(&data.player);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (!load_texture(&data, &data.graphics.wall_tex, "./textures/wall2.xpm"))
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	if (!data.mlx_win)
		return (free(data.mlx), 1);
	data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img.img_ptr)
		return (free(data.mlx), free(data.mlx_win), 1);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	render_frame(&data);
	mlx_hook(data.mlx_win, 2, 1L<<0, (void *)key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L<<17, (void *)close_window, &data);
	mlx_key_hook(data.mlx_win, move_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
/*
int main(int ac, char **av)
{
    t_bible     master;
    
    if (ac != 2)
    {
        printf("ERROR\nIncorrect file compilation");
        return (1);
    }
    initialize_master(&master);
	if (!parse_cub_file(&master, av[1]))
	{
		parsing_failure(master);
		return (1);
	}
}*/
