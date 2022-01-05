/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_resort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_rot_a(t_list **a, int n, int s_a)
{
	t_list	*cur;
	int		cnt;
	t_list	*min;

	cnt = -1;
	cur = *a;
	min = cur;
	while (++cnt < s_a)
	{
		if (n < cur->n && n > cur->prev->n)
			return (cnt);
		if (cur->n < min->n)
		{
			min = cur;
			min->min_cnt = cnt;
		}
		cur = cur->next;
	}
	return (min->min_cnt);
}

void	count_moves_for_put(t_list **a, t_list **b, int s_a, int s_b)
{
	t_list	*cur;
	int		cnt;

	cur = *b;
	cnt = -1;
	while (++cnt < s_b)
	{
		cur->rot_a = count_rot_a(a, cur->n, s_a);
		cur->rot_b = cnt;
		cur->flg_rot_a = 1;
		cur->flg_rot_b = 1;
		cur->flg_ready = cur->rot_a;
		if (cur->rot_b > cur->rot_a)
			cur->flg_ready = cur->rot_b;
		change_rev_rotate(cur, s_a, s_b);
		change_another_rotate(cur, s_a, s_b);
		cur = cur->next;
	}
}

t_list	*find_minimal(t_list **b, int size)
{
	t_list	*min;
	t_list	*cur;
	int		cnt;

	cnt = -1;
	cur = *b;
	min = *b;
	while (++cnt <= size)
	{
		if (cur->flg_ready < min->flg_ready)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

static void	do_it_for_diff_rotate(t_list **a, t_list **b, t_list *min)
{
	while (min->rot_a-- > 0)
	{
		if (min->flg_rot_a)
			rotate(a, 'a');
		else
			rev_rotate(a, 'a');
	}
	while (min->rot_b-- > 0)
	{
		if (min->flg_rot_b)
			rotate(b, 'b');
		else
			rev_rotate(b, 'b');
	}
}

void	do_it_for_min(t_list **a, t_list **b, t_list *min)
{
	if (min->flg_rot_a != min->flg_rot_b)
		do_it_for_diff_rotate(a, b, min);
	else
	{
		while (min->rot_a > 0 && min->rot_b > 0)
		{
			if (min->flg_rot_b)
				rotate_rotate(a, b);
			else
				reverse_reverse(a, b);
			min->rot_a--;
			min->rot_b--;
		}
		do_it_for_diff_rotate(a, b, min);
	}
	push(a, b, 'a');
}
