/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:42:56 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/01 16:31:11 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_we_texture(t_bible *master, char *line)
{
	line = skip_whitespace(line);
	trim_backend(line);
	master->graphics.we_path = ft_strdup(line);
}

void	assign_ea_texture(t_bible *master, char *line)
{
	line = skip_whitespace(line);
	trim_backend(line);
	master->graphics.ea_path = ft_strdup(line);
}

void	assign_so_texture(t_bible *master, char *line)
{
	line = skip_whitespace(line);
	trim_backend(line);
	master->graphics.so_path = ft_strdup(line);
}

void	assign_no_texture(t_bible *master, char *line)
{
	line = skip_whitespace(line);
	trim_backend(line);
	master->graphics.no_path = ft_strdup(line);
}

int	parse_textures(t_bible *master, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (!check_dup_no(master))
			return (0);
		assign_no_texture(master, line + 2);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (!check_dup_so(master))
			return (0);
		assign_so_texture(master, line + 2);
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (!check_dup_ea(master))
			return (0);
		assign_ea_texture(master, line + 2);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (!check_dup_we(master))
			return (0);
		assign_we_texture(master, line + 2);
	}
	return (1);
}
