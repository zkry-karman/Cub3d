/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_RGB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:43:09 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/09 16:13:24 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_rgb_values(char **rgb)
{
	int		i;
	long	value;

	i = 0;
	while (rgb[i])
	{
		if (!is_all_dig(rgb[i]))
			return (printf("Error\nRGB values must contain digits only\n"), 0);
		if (ft_strlen(rgb[i]) > 3)
			return (printf("Error\nRGB value overflows standard range\n"), 0);
		value = ft_atol(rgb[i]);
		if (value < 0 || value > 255)
		{
			printf("Error\nInvalide floor or ceiling color\n");
			printf("Values must be between 0 and 255\n");
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error\nIncorrect number of values for RGB\nNeed 3 values");
		return (0);
	}
	return (1);
}

char	**validate_rgb(char *line)
{
	char	**rgb;
	char	*trimmed;

	line = skip_whitespace(line);
	trimmed = ft_strtrim(line, " \t\n\r\v\f");
	if (!trimmed)
		return (NULL);
	rgb = ft_split(trimmed, ',');
	free(trimmed);
	if (!rgb)
		return (NULL);
	if (!validate_rgb_values(rgb))
	{
		free_double_pointer(rgb);
		return (NULL);
	}
	return (rgb);
}

void	assign_floor_rgb(t_bible *master, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	master->graphics.floor_color = (r << 16) | (g << 8) | b;
}

void	assign_ceiling_rgb(t_bible *master, char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	master->graphics.ceiling_color = (r << 16) | (g << 8) | b;
}

int	parse_rgb(t_bible *master, char *line)
{
	char	**rgb;

	rgb = NULL;
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (!check_dup_rgb(master, line))
			return (0);
		rgb = validate_rgb(line + 1);
		if (!rgb)
			return (0);
		assign_floor_rgb(master, rgb);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (!check_dup_rgb(master, line))
			return (0);
		rgb = validate_rgb(line + 1);
		if (!rgb)
			return (0);
		assign_ceiling_rgb(master, rgb);
	}
	if (rgb)
		free_double_pointer(rgb);
	return (1);
}
