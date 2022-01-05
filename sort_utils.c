/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_2(t_list **lst)
{
	(*lst)->flg_last = 0;
	(*lst)->next->flg_last = 1;
	(*lst)->prev = (*lst)->next;
	(*lst)->next->next = (*lst);
}

void	swap(t_list **lst, char name_stack)
{
	t_list	*tmp;
	t_list	*tmp_next;
	t_list	*tmp_prev;

	if (!lst || !(*lst) || (*lst)->next == *lst)
		return ;
	tmp = *lst;
	tmp_next = tmp->next->next;
	tmp_prev = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp->next->next->prev = tmp;
	*lst = tmp->next;
	(*lst)->next = tmp;
	(*lst)->prev = tmp_prev;
	tmp->next = tmp_next;
	tmp->prev = (*lst);
	if ((*lst)->flg_last)
		swap_2(lst);
	if (name_stack == 'a')
		write(1, "sa\n", 3);
	else if (name_stack == 'b')
		write(1, "sb\n", 3);
}

static void	add_2_empty_list(t_list **lst, t_list *new)
{
	new->next = new;
	new->prev = new;
	new->flg_last = 1;
	*lst = new;
}

static void	delete_first(t_list **lst)
{
	t_list	*tmp;

	if ((*lst)->flg_last)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
}

void	push(t_list	**dst, t_list **src, char name_stack)
{
	t_list	*new;

	if (*src == NULL)
		return ;
	new = ft_lstnew((*src)->n);
	if (!new)
		exit_program(dst, src, 1);
	if (*dst == NULL)
		add_2_empty_list(dst, new);
	else
	{
		new->next = (*dst);
		new->prev = (*dst)->prev;
		new->prev->next = new;
		new->next->prev = new;
		*dst = new;
	}
	delete_first(src);
	if (name_stack == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
