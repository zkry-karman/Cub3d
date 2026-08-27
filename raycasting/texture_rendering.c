/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:36:15 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/08/27 20:39:28 by kzhu@student.42.f###   ########.fr       */
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
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		return (printf("Error\nFailed to load XPM texture: %s\n", path), 0);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bits_per_pixel, &tex->line_length, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	load_all_textures(t_bible *master)
{
	if (!load_texture(master,
			&master->graphics.no_tex, master->graphics.no_path))
		return (0);
	if (!load_texture(master,
			&master->graphics.so_tex, master->graphics.so_path))
		return (0);
	if (!load_texture(master,
			&master->graphics.ea_tex, master->graphics.ea_path))
		return (0);
	if (!load_texture(master,
			&master->graphics.we_tex, master->graphics.we_path))
		return (0);
	return (1);
}

unsigned int	get_texture_pixel(t_img *tex, int x, int y)
{
	char	*src;

	src = tex->addr + y * tex->line_length + x * (tex->bits_per_pixel / 8);
	return (*(unsigned int *)src);
}
