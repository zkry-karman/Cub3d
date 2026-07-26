/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 15:37:20 by karmanz           #+#    #+#             */
/*   Updated: 2026/07/26 15:48:10 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_dup_no(t_bible *master)
{
    if (master->graphics.no_path)
    {
        printf("Error\nDuplicate north texture");
        return (0);
    }
    return (1);
}

int check_dup_so(t_bible *master)
{
    if (master->graphics.so_path)
    {
        printf("Error\nDuplicate south texture");
        return (0);
    }
    return (1);
}

int check_dup_ea(t_bible *master)
{
    if (master->graphics.ea_path)
    {
        printf("Error\nDuplicate east texture");
        return (0);
    }
    return (1);
}

int check_dup_we(t_bible *master)
{
    if (master->graphics.we_path)
    {
        printf("Error\nDuplicate west texture");
        return (0);
    }
    return (1);
}