/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:03:31 by zkarman           #+#    #+#             */
/*   Updated: 2026/08/25 15:47:52 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_lists
{
	char			*strbuff;
	struct s_lists	*next;
}		t_lists;
char	*get_next_line(int fd);
int		ft_setup_nextcall(t_lists **list, t_lists *lastnode);
char	*ft_fetchline(t_lists *list);
void	ft_makenode(t_lists **list, char *buff);
void	ft_makelist(t_lists **list, int fd);
void	ft_copyline(t_lists *list, char *str);
int		ft_totallen(t_lists *list);
t_lists	*ft_lstlast_gnl(t_lists *lst);
void	ft_freenodes(t_lists **list, t_lists *freshnode, char *buff);
int		ft_foundnewline(t_lists *list);

#endif
