/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:11:59 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/01 15:35:08 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_bible *master, char *line, t_line *lines)
{
	if (master->map.width == 0 || master->map.width < ft_strlen_cub3d(line))
		master->map.width = ft_strlen_cub3d(line);
	ft_add_new_node(&lines, line);
	master->map.height++;
}

void	initialize_minimap_stats(t_bible *master)
{
	master->mini.rad = 50;
	master->mini.mid[0] = 20 + master->mini.rad;
	master->mini.mid[1] = 20 + master->mini.rad;
}

char	*trim_backend(char *str)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'
			|| str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
	return (str);
}
