/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/30 15:18:12 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_bible		master;

    if (ac != 2)
        return (printf("ERROR\nIncorrect file compilation\n"), 1);
    initialize_master(&master);
	if (!parse_cub_file(&master, av[1]))
		return (parsing_failure(&master), 1);
	init_player_direction(&master.player);
	init_camera_plane(&master.player);
	master.mlx = mlx_init();
	if (!master.mlx)
		return (parsing_failure(&master), 1);
	master.mlx_win = mlx_new_window(master.mlx, WIDTH, HEIGHT, "cub3d");
	if (!master.mlx_win)
		return (parsing_failure(&master), free(master.mlx), 1);
	master.img.img_ptr = mlx_new_image(master.mlx, WIDTH, HEIGHT);
	if (!master.img.img_ptr)
		return (parsing_failure(&master), free(master.mlx), free(master.mlx_win), 1);
	master.img.addr = mlx_get_data_addr(master.img.img_ptr, &master.img.bits_per_pixel, &master.img.line_length, &master.img.endian);
	if (!load_all_textures(&master))
		return (parsing_failure(&master), 1);
	render_frame(&master);
	mlx_hook(master.mlx_win, 2, 1L<<0, (void *)key_press, &master);
	mlx_hook(master.mlx_win, 17, 1L<<17, (void *)close_window, &master);
	mlx_key_hook(master.mlx_win, move_hook, &master);
	mlx_loop(master.mlx);
	return (0);
}

