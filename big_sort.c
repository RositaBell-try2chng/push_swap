/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mark_min_max_value(t_list **a, int argc)
{
	t_list	*cur;

	cur = *a;
	if (cur->n == argc)
		cur->flg_max = 1;
	cur = cur->next;
	while (cur != *a)
	{
		if (cur->i == argc)
			cur->flg_max = 1;
		else if (cur->i == 0)
			cur->flg_min = 1;
		cur = cur->next;
	}
	if (cur->i == argc)
		cur->flg_max = 1;
	else if (cur->i == 0)
		cur->flg_min = 1;
}

static char	math_method(t_list **a)
{
	int	cnt_x;
	int	rev_cnt_x;
	int	gr_th;
	int	rev_gr_th;

	cnt_x = count_min_index(a);
	rev_cnt_x = count_max_index(a);
	gr_th = count_great(a);
	rev_gr_th = count_great_rev(a);
	if (cnt_x > rev_cnt_x && cnt_x > gr_th && cnt_x > rev_gr_th)
		return (0);
	if (gr_th > cnt_x && gr_th > rev_cnt_x && gr_th > rev_gr_th)
		return (2);
	if (rev_gr_th > gr_th && rev_gr_th > rev_cnt_x && rev_gr_th > cnt_x)
		return (3);
	return (1);
}

static t_list	*last_re_sort(t_list **a, t_list **b, int s_a, int s_b)
{
	t_list	*min;
	int		cnt;

	if (s_b == 0)
	{
		cnt = 0;
		min = *a;
		while (min->prev->n < min->n)
		{
			cnt++;
			min = min->next;
		}
		min->rot_a = cnt;
		min->flg_rot_a = 1;
		if (cnt > s_a / 2)
		{
			min->rot_a = s_a - cnt;
			min->flg_rot_a = 0;
		}
		return (min);
	}
	count_moves_for_put(a, b, s_a, s_b);
	min = find_minimal(b, s_b);
	do_it_for_min(a, b, min);
	return (last_re_sort(a, b, ++s_a, --s_b));
}

static void	count_size(t_list **b, int *size_b)
{
	t_list	*cur;

	*size_b = 0;
	cur = *b;
	while (cur && cur->flg_last != 1)
	{
		cur = cur->next;
		(*size_b)++;
	}
	if (cur)
		(*size_b)++;
}

void	big_sort(t_list **a, t_list **b, int argc)
{
	char	res;
	int		size_a;
	int		size_b;
	t_list	*min;

	transform_numbers(a);
	mark_min_max_value(a, argc - 1);
	res = math_method(a);
	if (res == 0)
		index_sort(a);
	else if (res == 1)
		index_rev_sort(a, argc);
	else if (res == 2)
		gr_th_sort(a);
	else
		gr_th_rev_sort(a);
	push_b_2_b(a, b);
	count_size(b, &size_b);
	size_a = argc - size_b;
	min = last_re_sort(a, b, size_a, size_b);
	while (min->flg_rot_a && --min->rot_a >= 0)
		rotate(a, 'a');
	while (!(min->flg_rot_a) && --min->rot_a >= 0)
		rev_rotate(a, 'a');
}
