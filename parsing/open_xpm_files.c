/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_xpm_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:50:37 by karmanz           #+#    #+#             */
/*   Updated: 2026/08/04 14:00:40 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    close_xpm_files(int no, int so, int ea, int we)
{
    if (no > 0)
        close (no);
    if (so > 0)
        close (so);
    if (ea > 0)
        close (ea);
    if (we > 0)
        close (we);
}

int check_xpm_files(t_bible *master)
{
    int fd_no;
    int fd_so;
    int fd_ea;
    int fd_we;
    
    if (!master->graphics.no_path || !master->graphics.ea_path || !master->graphics.so_path || !master->graphics.we_path)
    {
        printf("Error\nMissing a .XPM file\n");
        return (0);
    }
    fd_no = open(master->graphics.no_path, O_RDONLY);
    fd_so = open(master->graphics.so_path, O_RDONLY);
    fd_ea = open(master->graphics.ea_path, O_RDONLY);
    fd_we = open(master->graphics.we_path, O_RDONLY);
    if (fd_no < 0 || fd_so < 0 || fd_ea < 0 || fd_we < 0)
    {
        printf("Error\n One or more .XPM files cannot be opened\n");
        close_xpm_files(fd_no, fd_so, fd_ea, fd_we);
        return (0);
    }
    close_xpm_files(fd_no, fd_so, fd_ea, fd_we);
    return (1);
}