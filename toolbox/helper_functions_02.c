/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:11:59 by zkarman           #+#    #+#             */
/*   Updated: 2026/09/09 17:23:04 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_all_dig(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			return (-1);
		i++;
	}
	return (res * sign);
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
