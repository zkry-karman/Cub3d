/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:01:41 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/25 17:45:41 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *skip_whitespace(char *line)
{
    while ((*line >= 9 && *line <= 13) || *line == 32)
        line++;
    return (line);
}

int     ft_strlen_cub3d(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    return (i);
}

t_line  *ft_lstlast_cub3d(t_line *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

void    ft_add_new_node(t_line **list, char *line)
{
    t_line  *newnode;
    t_line  *lastnode;

    if (!list || !line)
        return ;
    lastnode = ft_lstlast_cub3d(*list);
    newnode = malloc(sizeof(t_line));
    if (!newnode)
        return (free(line));
    if (!lastnode)
        *list = newnode;
    else
        lastnode->next = newnode;
    newnode->line = line;
    newnode->next = NULL;
}

char    **duplicate_map(char **og_map, int height)
{
    char    **dup;
    int     y;

    dup = malloc(sizeof(char *) * (height + 1));
    if (!dup)
        return (NULL);
    
    y = 0;
    while (y < height)
    {
        dup[y] = ft_strdup(og_map[y]);
        y++;
    }
    dup[y] = NULL;
    return (dup);
}