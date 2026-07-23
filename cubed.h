/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:17:02 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/20 16:43:48 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     players;

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

    void        *mlx;
    void        *mlx_win;
    
    
}   t_bible;


#endif