/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/07/24 16:36:48 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_bible data;
	
	init_mock_data(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	if (!data.mlx_win)
		return (free(data.mlx), 1);
	mlx_hook(data.mlx_win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L<<17, close_window, &data);
	mlx_loop(data.mlx);
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
	parse_file(&master, av[1]);
}
