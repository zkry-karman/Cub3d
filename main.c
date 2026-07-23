/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:48:41 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/07/23 17:49:35 by kzhu@student.42.f###   ########.fr       */
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
	data.mlx_win = mlx_new_window(data.mlx, 1024, 800, "cub3d");
	if (!data.mlx)
		return (free(data.mlx), 1);
	mlx_loop(data.mlx);

int main(int ac, char **av)
{
    t_bible     master;
    
    if (ac != 2)
    {
        printf("ERROR\nIncorrect file compilation");
        return (1);
    }
    initialize_master(&master);
}