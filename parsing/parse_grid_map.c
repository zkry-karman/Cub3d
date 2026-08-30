/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:43:21 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/30 16:13:09 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	flood_fill(t_bible *master, char **map_copy, int y, int x)
{
	if (x < 0 || x >= master->map.width || y < 0 || y >= master->map.height)
		return (0);
	if (map_copy[y][x] == ' ')
		return (0);
	if (map_copy[y][x] == '1' || map_copy[y][x] == '#')
		return (1);
	map_copy[y][x] = '#';
	if (!flood_fill(master, map_copy, y + 1, x)
		|| !flood_fill(master, map_copy, y - 1, x)
		|| !flood_fill(master, map_copy, y, x + 1)
		|| !flood_fill(master, map_copy, y, x - 1))
		return (0);
	return (1);
}

int	check_characters(t_bible *master)
{
	int	x;
	int	y;

	if (master->player.player_count != 1)
		return (printf("Error\nMust have 1 player"), 0);
	y = 0;
	while (y < master->map.height)
	{
		x = 0;
		while (x < master->map.width)
		{
			if (master->map.grid[y][x] != '1' && master->map.grid[y][x] != '0' && master->map.grid[y][x] != ' ')
				return (printf("Error\nInvalid character in map"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

void	store_player_pos(t_bible *master, int x, int y, char direction)
{
	master->player.x = x + 0.5;
	master->player.y = y + 0.5;
	master->player.dir = direction;
	master->map.grid[y][x] = '0';
	master->player.player_count++;
}

int	pad_copy_map(t_bible *master, t_line *line_list)
{
	int		x;
	int		y;
	t_line		*curr;

	master->map.grid = malloc(sizeof(char *) * (master->map.height + 1));
	if (!master->map.grid)
		return (0);
	y = 0;
	curr = line_list;
	while (curr)
	{
		master->map.grid[y] = malloc(sizeof(char) * (master->map.width + 1));
		if (!master->map.grid[y])
			return (0);
		x = 0;
		x = scan_copy_line(master, curr, x, y);
		x = pad_empty_spaces(master, x, y);
		master->map.grid[y][x] = '\0';
		curr = curr->next;
		y++;
	}
	master->map.grid[y] = NULL;
	return (1);
}

int	parse_map(t_bible *master, char *head, int fd)
{
	t_line	*lines;
	char	*line;
	char	**map_copy;

	lines = initialize_map_dimensions(master, head);
	while ((line = get_next_line(fd)))
	{
		if (master->map.width == 0 || master->map.width < ft_strlen_cub3d(line))
			master->map.width = ft_strlen_cub3d(line);
		ft_add_new_node(&lines, line);
		master->map.height++;
	}
	if (!pad_copy_map(master, lines))
		return (ft_lstclear_cub3d(&lines, free), 0);
	ft_lstclear_cub3d(&lines, free);
	if (!check_characters(master))
		return (0);
	map_copy = duplicate_map(master->map.grid, master->map.height);
	if (!map_copy)
		return (0);
	if (!flood_fill(master, map_copy, (int)master->player.y, (int)master->player.x))
		return (printf("Error\nMap is not fully enclosed\n"), free_double_pointer(map_copy), 0);
	return (free_double_pointer(map_copy), 1);
}
