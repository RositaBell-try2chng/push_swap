/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (NULL == elem)
		return (NULL);
	elem->n = n;
	elem->flg_last = 0;
	elem->flg_max = 0;
	elem->flg_min = 0;
	elem->min_cnt = 0;
	elem->flg_ready = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

char	add_new_elem(t_list **a, int n, int i)
{
	t_list			*new;
	static t_list	*tmp;

	new = ft_lstnew(n);
	if (!new)
		return (0);
	if (i == 0)
	{
		*a = new;
		tmp = new;
		return (1);
	}
	tmp->next = new;
	new->prev = tmp;
	tmp = new;
	return (1);
}

void	connect_first_last(t_list **a)
{
	t_list	*tmp;
	t_list	*first;

	first = *a;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	first->prev = tmp;
	tmp->next = first;
	tmp->flg_last = 1;
}

void	free_list(t_list **lst)
{
	t_list	*cur;

	if (!lst)
		return ;
	cur = *lst;
	while (cur && cur->next && cur->flg_last != 1)
	{
		cur = cur->next;
		free(cur->prev);
		cur->prev = NULL;
	}
	free(cur);
	free(lst);
}
