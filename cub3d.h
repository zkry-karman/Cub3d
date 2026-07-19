/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:17:02 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/19 14:32:38 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

typedef struct s_map
{
    
}   t_map;

typedef struct s_graphic
{
    
}   t_graphic;

typedef struct s_pos
{
    
}   t_pos;

typedef struct  s_bible
{
    t_map       *map;
    t_graphic   *graphics;
    t_pos       *player_pos;
    int         map_width;
    int         map_height;

    void        *mlx;
    void        *mlx_win;
    
    
}   t_bible;


#endif