/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushimom <yushimom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:40:45 by yushimom          #+#    #+#             */
/*   Updated: 2023/04/15 21:19:21 by yushimom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_line	*ft_lstnew_mapline(char *read_line)
{
	t_map_line	*res;

	res = (t_map_line *)my_malloc(sizeof(t_map_line));
	res->line = read_line;
	res->next = NULL;
	return (res);
}

t_point	*ft_lstlast(t_point *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_point **lst, t_point *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}

t_map_line	*ft_lstlast_ml(t_map_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ml(t_map_line **lst, t_map_line *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast_ml(*lst)->next = new;
	}
}

void	ft_lstadd_front(t_point **lst, t_point *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		(*lst)->prev = new;
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_map_line *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// void	ft_lstclear(t_list **lst)
// {
// 	t_list	*tmp;

// 	if (!lst)
// 		return ;
// 	while (*lst != NULL)
// 	{
// 		tmp = (*lst)->next;
// 		free(*lst);
// 		*lst = tmp;
// 	}
// }
