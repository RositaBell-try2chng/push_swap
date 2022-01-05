/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rewrite_stack(t_min *min)
{
	static int	cnt;

	min->min0->i = cnt++;
	min->min0->flg_ready = 1;
	if (min->min1)
	{
		min->min1->i = cnt++;
		min->min1->flg_ready = 1;
	}
	if (min->min2)
	{
		min->min2->i = cnt++;
		min->min2->flg_ready = 1;
	}
	if (min->min3)
	{
		min->min3->i = cnt++;
		min->min3->flg_ready = 1;
	}
	if (min->min4)
	{
		min->min4->i = cnt++;
		min->min4->flg_ready = 1;
	}
}

static char	null_min(t_list **a, t_min *min)
{
	t_list	*cur;

	cur = *a;
	min->min1 = NULL;
	min->min2 = NULL;
	min->min3 = NULL;
	min->min4 = NULL;
	while (cur->flg_ready && !cur->flg_last)
		cur = cur->next;
	if (!cur->flg_ready)
		min->min0 = cur;
	else
		return (1);
	return (0);
}

static void	find_next_minimal(t_list *cur, t_min *min)
{
	while (!cur->flg_last)
	{
		if (!cur->next->flg_ready)
		{
			if (cur->next->n < min->min0->n)
				rewrite_minimal(cur->next, min, 0);
			else if (!min->min1)
				min->min1 = cur->next;
			else if (cur->next->n < min->min1->n)
				rewrite_minimal(cur->next, min, 1);
			else if (!min->min2)
				min->min2 = cur->next;
			else if (cur->next->n < min->min2->n)
				rewrite_minimal(cur->next, min, 2);
			else if (!min->min3)
				min->min3 = cur->next;
			else if (cur->next->n < min->min3->n)
				rewrite_minimal(cur->next, min, 3);
			else if (!min->min4 || cur->next->n < min->min4->n)
				min->min4 = cur->next;
		}
		cur = cur->next;
	}
}

void	transform_numbers(t_list **a)
{
	t_list	*cur;
	t_min	*min;
	char	f_ready;

	min = malloc(sizeof(t_min));
	if (!min)
		exit_program(a, NULL, 1);
	f_ready = null_min(a, min);
	cur = min->min0;
	while (!f_ready)
	{
		find_next_minimal(cur, min);
		rewrite_minimal(NULL, min, 4);
		rewrite_stack(min);
		f_ready = null_min(a, min);
	}
	free(min);
}
