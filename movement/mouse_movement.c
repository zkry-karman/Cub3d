/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 19:24:07 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/27 20:50:33 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_bible *data)
{
	double	angle;
	int		mouse_offset_x;

	(void)y;
	mouse_offset_x = x - WIDTH / 2;
	if (mouse_offset_x == 0)
		return (0);
	angle = mouse_offset_x * MOUSE_SPEED;
	rotate_player(&data->player, angle);
	mlx_mouse_move(data->mlx, data->mlx_win,
		WIDTH / 2, HEIGHT / 2);
	render_frame(data);
	return (0);
}

int	mouse_enter(t_bible *data)
{
	mlx_mouse_hide(data->mlx, data->mlx_win);
	return (0);
}

int	mouse_leave(t_bible *data)
{
	mlx_mouse_show(data->mlx, data->mlx_win);
	return (0);
}
