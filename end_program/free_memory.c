/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:30:12 by karmanz           #+#    #+#             */
/*   Updated: 2026/09/01 16:35:12 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_double_pointer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_lstdelone_cub3d(t_line *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->line);
	free(lst);
	return ;
}

void	ft_lstclear_cub3d(t_line **lst, void (*del)(void *))
{
	t_line	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone_cub3d(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
	return ;
}
