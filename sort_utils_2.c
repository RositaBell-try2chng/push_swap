/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst, char name_stack)
{
	if (!(*lst) || (*lst)->flg_last)
		return ;
	(*lst)->prev->flg_last = 0;
	(*lst)->flg_last = 1;
	*lst = (*lst)->next;
	if (name_stack == 'a')
		write(1, "ra\n", 3);
	else if (name_stack == 'b')
		write(1, "rb\n", 3);
	(void )name_stack;
}

void	rotate_rotate(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	rev_rotate(t_list **lst, char name_stack)
{
	if (!(*lst) || (*lst)->flg_last)
		return ;
	(*lst)->prev->flg_last = 0;
	(*lst)->prev->prev->flg_last = 1;
	*lst = (*lst)->prev;
	if (name_stack == 'a')
		write(1, "rra\n", 4);
	else if (name_stack == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_reverse(t_list **a, t_list **b)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	write(1, "rrr\n", 4);
}

void	swap_swap(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}
