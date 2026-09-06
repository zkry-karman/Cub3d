/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:37:20 by karmanz           #+#    #+#             */
/*   Updated: 2026/09/06 16:49:24 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_dup_no(t_bible *master)
{
	if (master->graphics.no_path)
	{
		printf("Error\nDuplicate north texture\n");
		return (0);
	}
	return (1);
}

int	check_dup_so(t_bible *master)
{
	if (master->graphics.so_path)
	{
		printf("Error\nDuplicate south texture\n");
		return (0);
	}
	return (1);
}

int	check_dup_ea(t_bible *master)
{
	if (master->graphics.ea_path)
	{
		printf("Error\nDuplicate east texture\n");
		return (0);
	}
	return (1);
}

int	check_dup_we(t_bible *master)
{
	if (master->graphics.we_path)
	{
		printf("Error\nDuplicate west texture\n");
		return (0);
	}
	return (1);
}

int	check_dup_rgb(t_bible *master, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (master->graphics.floor_color != -1)
		{
			printf("Error\nDuplicate floor color\n");
			return (0);
		}
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (master->graphics.ceiling_color != -1)
		{
			printf("Error\nDuplicate ceiling color\n");
			return (0);
		}
	}
	return (1);
}
