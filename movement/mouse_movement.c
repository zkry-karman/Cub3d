/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 19:24:07 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/09/09 16:12:54 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_bible *data)
{
	double		angle;
	int			movement;
	static int	last_x;

	(void)y;
	last_x = WIDTH / 2;
	movement = x - last_x;
	if (movement == 0)
		return (0);
	angle = movement * MOUSE_SPEED;
	rotate_player(&data->player, angle);
	last_x = x;
	if (x < 100 || x > WIDTH - 100)
	{
		mlx_mouse_move(data->mlx, data->mlx_win,
			WIDTH / 2, HEIGHT / 2);
		last_x = WIDTH / 2;
	}
	render_frame(data);
	return (0);
}
