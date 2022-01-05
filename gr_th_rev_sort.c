/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_th_rev_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gr_th_rev_sort(t_list **a)
{
	t_list	*tmp;
	t_list	*cur;
	int		tmp_n;

	cur = *a;
	while (cur->next->flg_max == 0)
		cur = cur->prev;
	tmp = cur->next;
	tmp_n = tmp->n;
	cur->next->flg_stack = 'a';
	while (cur != tmp)
	{
		if (cur->n < tmp_n)
		{
			cur->flg_stack = 'a';
			tmp_n = cur->n;
		}
		else
			cur->flg_stack = 'b';
		cur = cur->prev;
	}
}
