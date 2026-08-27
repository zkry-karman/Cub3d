/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:51:57 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/25 15:47:59 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freenodes(t_lists **list, t_lists *freshnode, char *buff)
{
	t_lists	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->strbuff);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (freshnode)
	{
		if (freshnode->strbuff[0])
			*list = freshnode;
		else
		{
			free(buff);
			free(freshnode);
		}
	}
}

void	ft_copyline(t_lists *list, char *str)
{
	int	i;
	int	k;

	if (!list || !str)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->strbuff[i])
		{
			if (list->strbuff[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->strbuff[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	ft_totallen(t_lists *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->strbuff[i])
		{
			if (list->strbuff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	ft_foundnewline(t_lists *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->strbuff[i])
		{
			if (list->strbuff[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_lists	*ft_lstlast_gnl(t_lists *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
