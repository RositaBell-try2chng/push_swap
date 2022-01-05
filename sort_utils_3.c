/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_min_index(t_list **a)
{
	t_list	*cur;
	t_list	*tmp;
	int		cnt;

	cur = *a;
	cnt = 1;
	while (cur->flg_min == 0)
		cur = cur->next;
	tmp = cur;
	cur = cur->next;
	while (cur != tmp)
	{
		if (cur->i == cnt)
			cnt++;
		cur = cur->next;
	}
	return (cnt);
}

int	count_max_index(t_list **a)
{
	t_list	*cur;
	t_list	*tmp;
	int		tmp_i;
	int		cnt;

	cur = *a;
	cnt = 1;
	while (cur->flg_max == 0)
		cur = cur->prev;
	tmp = cur;
	tmp_i = cur->i;
	cur = cur->prev;
	while (cur != tmp)
	{
		if (tmp_i - cur->i == cnt)
			cnt++;
		cur = cur->prev;
	}
	return (cnt);
}

int	count_great(t_list **a)
{
	t_list	*cur;
	t_list	*tmp;
	int		tmp_n;
	int		cnt;

	cnt = 1;
	cur = *a;
	while (cur->flg_min == 0)
		cur = cur->next;
	tmp_n = cur->n;
	tmp = cur;
	cur = cur->next;
	while (cur != tmp)
	{
		if (cur->n > tmp_n)
		{
			cnt++;
			tmp_n = cur->n;
		}
		cur = cur->next;
	}
	return (cnt);
}

int	count_great_rev(t_list **a)
{
	t_list	*cur;
	t_list	*tmp;
	int		tmp_n;
	int		cnt;

	cnt = 1;
	cur = *a;
	while (cur->flg_max == 0)
		cur = cur->prev;
	tmp_n = cur->n;
	tmp = cur;
	cur = cur->prev;
	while (cur != tmp)
	{
		if (cur->n < tmp_n)
		{
			cnt++;
			tmp_n = cur->n;
		}
		cur = cur->prev;
	}
	return (cnt);
}
