/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:11:59 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/22 16:14:58 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *trim_backend(char *str)
{
    int len;

    if (!str)
        return (NULL);
    len = ft_strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'
        || str[len - 1] == '\n' || str[len - 1] == '\r'))
    {
        str[len - 1] = '\0';
        len--;
    }
    return (str);
}