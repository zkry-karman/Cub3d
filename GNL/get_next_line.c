/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:47:18 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/25 16:05:48 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_setup_nextcall(t_lists **list, t_lists *lastnode)
{
	t_lists	*freshnode;
	char	*buff;
	int		i;
	int		k;

	buff = malloc(BUFFER_SIZE + 1);
	freshnode = malloc(sizeof(t_lists));
	if (!buff || !freshnode)
	{
		free(buff);
		free(freshnode);
		return (0);
	}
	i = 0;
	k = 0;
	while (lastnode->strbuff[i] && lastnode->strbuff[i] != '\n')
		i++;
	while (lastnode->strbuff[i] && lastnode->strbuff[i++])
		buff[k++] = lastnode->strbuff[i];
	buff[k] = '\0';
	freshnode->strbuff = buff;
	freshnode->next = NULL;
	ft_freenodes(list, freshnode, buff);
	return (1);
}

char	*ft_fetchline(t_lists *list)
{
	char	*nextline;
	int		strlen;

	strlen = ft_totallen(list);
	nextline = malloc(strlen + 1);
	if (!nextline)
		return (NULL);
	ft_copyline(list, nextline);
	return (nextline);
}

void	ft_makenode(t_lists **list, char *buff)
{
	t_lists	*newnode;
	t_lists	*lastnode;

	if (!list || !buff)
		return ;
	lastnode = ft_lstlast_gnl(*list);
	newnode = malloc(sizeof(t_lists));
	if (!newnode)
	{
		free(buff);
		return ;
	}
	if (!lastnode)
		*list = newnode;
	else
		lastnode->next = newnode;
	newnode->strbuff = buff;
	newnode->next = NULL;
}

void	ft_makelist(t_lists **list, int fd)
{
	int		char_read;
	char	*buff;

	while (!ft_foundnewline(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buff);
			ft_freenodes(list, NULL, NULL);
			return ;
		}
		if (char_read == 0)
		{
			free(buff);
			break ;
		}
		buff[char_read] = '\0';
		ft_makenode(list, buff);
	}
}

char	*get_next_line(int fd)
{
	char			*nextline;
	static t_lists	*list;
	t_lists			*temp;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &nextline, 0) < 0)
	{
		while (list)
		{
			temp = list->next;
			free(list->strbuff);
			free(list);
			list = temp;
		}
		list = NULL;
		return (NULL);
	}
	ft_makelist(&list, fd);
	if (!list)
		return (NULL);
	nextline = ft_fetchline(list);
	ft_setup_nextcall(&list, ft_lstlast_gnl(list));
	return (nextline);
}
