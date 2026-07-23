/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:43:43 by zkarman           #+#    #+#             */
/*   Updated: 2026/07/20 16:17:07 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int main(int ac, char **av)
{
    t_bible     master;
    
    if (ac != 2)
    {
        printf("ERROR\nIncorrect file compilation");
        return (1);
    }
    initialize_master(&master);
}