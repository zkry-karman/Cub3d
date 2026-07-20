/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_master_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:15:11 by karmanz           #+#    #+#             */
/*   Updated: 2026/07/20 16:44:10 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    nullify_variables(t_bible *master)
{
    game->map->height = 0;
    game->map->width = 0;
    game->map->grid = NULL;
}

void    malloc_structs(t_bible *master)
{
    master->map = malloc(sizeof(struct s_map));
    master->grahics = malloc(sizeof(struct s_graphic));
    master->player_pos = malloc(sizeof(struct s_pos));
    if (!master->map || !master->grahics || !master->player_pos)
    {
        perror("Malloc");
        free_malloc(master);
        exit (EXIT_FAILURE);
    }
}

void    initialize_master(t_bible *master)
{
    malloc_structs(master);
    nullify_variables(master);
}