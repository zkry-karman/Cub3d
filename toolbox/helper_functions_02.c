/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:11:59 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/06 16:52:10 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_all_dig(char *str)
{
	int		i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long		ft_atol(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 2147483647)
			return (2147483648L);
		i++;
	}
	return (res);
}

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
