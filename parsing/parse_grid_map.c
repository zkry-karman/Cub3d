/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:43:21 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/27 21:26:53 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_map(t_bible *master, char *head, int fd)
{
    t_line  *lines;
    char    *line;

    lines = ft_add_line_node(&lines, head);
}