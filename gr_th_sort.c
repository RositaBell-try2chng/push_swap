/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_th_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gr_th_sort(t_list **a)
{
	t_list	*tmp;
	t_list	*cur;
	int		tmp_n;

	cur = *a;
	while (cur->prev->flg_min == 0)
		cur = cur->next;
	tmp = cur->prev;
	cur->prev->flg_stack = 'a';
	tmp_n = (cur)->prev->n;
	while (cur != tmp)
	{
		if (cur->n > tmp_n)
		{
			cur->flg_stack = 'a';
			tmp_n = cur->n;
		}
		else
			cur->flg_stack = 'b';
		cur = cur->next;
	}
}
