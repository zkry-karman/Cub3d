/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:21:47 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/04 13:50:02 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    read_file(t_bible *master, int fd)
{
    char    *line;
    char    *curr;
    
    while ((line = get_next_line(fd)))
    {
        curr = skip_whitespace(line);
        if (ft_strncmp(curr, "NO", 2) == 0 || ft_strncmp(curr, "SO", 2) == 0 || ft_strncmp(curr, "EA", 2) == 0 || ft_strncmp(curr, "WE", 2) == 0)
        {
            if (!parse_textures(master, curr))
                return (free(line), 0);
        }
        else if (ft_strncmp(curr, "F", 1) == 0 || ft_strncmp(curr, "C", 1) == 0)
        {
            if (!parse_rgb(master, curr))
                return (free(line), 0);
        }
        else if (ft_strncmp(curr, "1", 1) == 0 || ft_strncmp(curr, "0", 1) == 0 || ft_strncmp(curr, "N", 1) == 0 || ft_strncmp(curr, "S", 1) == 0 || ft_strncmp(curr, "E", 1) == 0 || ft_strncmp(curr, "W", 1) == 0)
        {
            if (!parse_map(master, line, fd))
                return (0);
            return (1);
        }
        free(line);
    }
    if (!check_xpm_files(master))
        return (0);
    return (1);
}

int check_extension(char *file_path)
{
    int len;

    if (!file_path)
        return (0);
    len = ft_strlen(file_path);
    if (len < 4)
        return (0);
    if (file_path[len - 4] == '.'
        && file_path[len - 3] == 'c'
        && file_path[len - 2] == 'u'
        && file_path[len - 1] == 'b')
        return (1);
    return (0);
}

int parse_cub_file(t_bible *master, char *file_path)
{
    int fd;

    if (!check_extension(file_path))
    {
        printf("Error\nMap file must have .cub extension\n");
        return (0);
    }
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nCannont open file\n");
        return (0);
    }
    if (!read_file(master, fd))
        parsing_failure(master);
    close(fd);
}