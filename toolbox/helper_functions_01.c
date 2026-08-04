/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:02:35 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/04 13:06:34 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_other_configs(t_bible *master)
{
    if (!master->graphics.no_path || !master->graphics.ea_path || !master->graphics.so_path || !master->graphics.we_path || master->graphics.floor_color == -1 || master->graphics.ceiling_color == -1)
        return (0);
    return (1);
}