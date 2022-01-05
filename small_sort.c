/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	check_need_swap(t_list **lst)
{
	t_list	*tmp;

	if ((*lst)->prev == (*lst)->next && (*lst)->n > (*lst)->next->n)
		return (1);
	tmp = (*lst);
	if (tmp->n < tmp->next->n && tmp->next->n < tmp->next->next->n)
		return (0);
	tmp = (*lst)->next;
	if (tmp->n < tmp->next->n && tmp->next->n < tmp->next->next->n)
		return (0);
	tmp = tmp->next;
	if (tmp->n < tmp->next->n && tmp->next->n < tmp->next->next->n)
		return (0);
	return (1);
}

void	sort_list(t_list **t, char name_stack, int size)
{
	if (size == 3)
	{
		if ((*t)->n < (*t)->next->n && (*t)->next->n < (*t)->next->next->n)
			return ;
		if (check_need_swap(t))
			swap(t, name_stack);
		if ((*t)->n < (*t)->next->n && (*t)->next->n < (*t)->next->next->n)
			return ;
		if ((*t)->next->n < (*t)->n && (*t)->next->n < (*t)->next->next->n)
			return (rotate(t, name_stack));
		else
			return (rev_rotate(t, name_stack));
	}
	if ((*t)->n > (*t)->next->n)
		swap(t, name_stack);
}

static void	push_remaining(t_list **a, t_list **b, int i, char flg)
{
	if (flg == 2)
	{
		rotate_rotate(a, b);
		while (--i >= 0)
			push(a, b, 'a');
	}
	else if (flg == 1)
	{
		while (--i >= 0)
		{
			push(a, b, 'a');
			rotate(a, 'a');
		}
	}
	else
	{
		while (--i >= 0)
		{
			rev_rotate(b, 'b');
			push(a, b, 'a');
		}
	}
}

static void	join_stacks(t_list **a, t_list **b, int i)
{
	t_list	*tmp;

	if ((*b)->n > (*a)->prev->n)
		return (push_remaining(a, b, i, 1));
	else if ((*b)->prev->n < (*a)->n)
		return (push_remaining(a, b, i, 0));
	tmp = (*a)->prev;
	while (i > 0 && (*a) != tmp)
	{
		while (i > 0 && (*b)->n < (*a)->n)
		{
			push(a, b, 'a');
			rotate(a, 'a');
			i--;
		}
		rotate(a, 'a');
	}
	while (i > 0 && (*b)->n < (*a)->n)
	{
		push(a, b, 'a');
		rotate(a, 'a');
		i--;
	}
	if (i > 0)
		return (push_remaining(a, b, i, 2));
}

void	small_sort(t_list **a, t_list **b, int argc)
{
	int	i;

	i = -1;
	if (argc == 2)
		return (swap(a, 'a'));
	if (argc == 3)
		return (sort_list(a, 'a', 3));
	while (++i < argc / 2)
		push(b, a, 'b');
	if (check_need_swap(a) && check_need_swap(b))
		swap_swap(a, b);
	sort_list(a, 'a', argc - i);
	sort_list(b, 'b', i);
	join_stacks(a, b, i);
	while ((*a)->n > (*a)->prev->n)
		rotate(a, 'a');
}
