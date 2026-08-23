/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/23 15:11:06 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	//t_bible data = {0};
	t_bible		master;

    if (ac != 2)
        return (printf("ERROR\nIncorrect file compilation"), 1);
    initialize_master(&master);
	if (!parse_cub_file(&master, av[1]))
		return (parsing_failure(master), 1);
	
	//Where are you getting the data to store init_player_direction ?
	if (!init_player_direction(&master.player))
	// need to free memory if this function fails but idk if we need this function ??
		return (1);
	init_camera_plane(&master.player);
	// what if this function fails ?
	master.mlx = mlx_init();
	if (!master.mlx)
	// need to free memory here if failure
		return (1);
	if (!load_texture(&master, &master.graphics.wall_tex, "./textures/wall2.xpm"))
	// need to free memory here if failure
		return (1);
	master.mlx_win = mlx_new_window(master.mlx, WIDTH, HEIGHT, "cub3d");
	if (!master.mlx_win)
	// need to free memory here if failure
		return (free(master.mlx), 1);
	master.img.img_ptr = mlx_new_image(master.mlx, WIDTH, HEIGHT);
	if (!master.img.img_ptr)
	// need to free memory here if failure
		return (free(master.mlx), free(master.mlx_win), 1);
	master.img.addr = mlx_get_data_addr(master.img.img_ptr, &master.img.bits_per_pixel, &master.img.line_length, &master.img.endian);
	render_frame(&master);
	mlx_hook(master.mlx_win, 2, 1L<<0, (void *)key_press, &master);
	mlx_hook(master.mlx_win, 17, 1L<<17, (void *)close_window, &master);
	mlx_key_hook(master.mlx_win, move_hook, &master);
	mlx_loop(master.mlx);
	return (0);
}

