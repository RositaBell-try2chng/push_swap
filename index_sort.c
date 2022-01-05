/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_sort(t_list **a)
{
	t_list	*tmp;
	t_list	*cur;
	int		index;

	index = 1;
	cur = *a;
	while (cur->prev->flg_min == 0)
		cur = cur->next;
	tmp = cur->prev;
	cur->prev->flg_stack = 'a';
	while (cur != tmp)
	{
		if (cur->i == index)
		{
			index++;
			cur->flg_stack = 'a';
		}
		else
			cur->flg_stack = 'b';
		cur = cur->next;
	}
}

void	push_b_2_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->prev;
	while ((*a) != tmp)
	{
		if ((*a)->flg_stack == 'b')
			push(b, a, 'b');
		else
			rotate(a, 'a');
	}
	if ((*a)->flg_stack == 'b')
		push(b, a, 'b');
}
