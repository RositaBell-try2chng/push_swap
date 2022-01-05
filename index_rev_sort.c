/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_rev_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_rev_sort(t_list **a, int argc)
{
	t_list	*tmp;
	t_list	*cur;
	int		index;

	index = argc - 2;
	cur = (*a);
	while (cur->next->flg_max == 0)
		cur = cur->prev;
	tmp = cur->next;
	cur->next->flg_stack = 'a';
	while (cur != tmp)
	{
		if (cur->i == index)
		{
			index--;
			cur->flg_stack = 'a';
		}
		else
			cur->flg_stack = 'b';
		cur = cur->prev;
	}
}
