/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:36:15 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/24 15:51:49 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_wall_texture(t_ray *ray, t_graphic *graphic)
{
	if (ray->wall_type == 0)
	{
		if (ray->step_x > 0)
			return (&graphic->we_tex);
		return (&graphic->ea_tex);
	}
	if (ray->step_y > 0)
		return (&graphic->no_tex);
	return (&graphic->so_tex);
}

int	load_texture(t_bible *data, t_img *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bits_per_pixel, &tex->line_length, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

unsigned int get_texture_pixel(t_img *tex, int x, int y)
{
	char *src;

	src = tex->addr + y * tex->line_length + x * (tex->bits_per_pixel / 8);
	return (*(unsigned int *)src);
}