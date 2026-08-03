/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/03 17:43:46 by kzhu@student.42.f###   ########.fr       */
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
	printf("Spawn direction: %c\n", data.player.dir);
	printf("Direction vector: (%.1f, %.1f)\n",
	data.player.dir_x, data.player.dir_y);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	if (!data.mlx_win)
		return (free(data.mlx), 1);
	data.img.img_ptr = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img.img_ptr)
		return (free(data.mlx), free(data.mlx_win), 1);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	render_background(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.img_ptr, 0, 0);
	render_frame(&data);
	mlx_hook(data.mlx_win, 2, 1L<<0, (void *)key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L<<17, (void *)close_window, &data);
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
	parse_cub_file(&master, av[1]);
}*/
