/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_resort_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	change_value_ready(t_list *cur, int rev_a, int rev_b, int flg)
{
	cur->flg_ready = flg;
	cur->flg_rot_b = 0;
	cur->flg_rot_a = 0;
	cur->rot_b = rev_b;
	cur->rot_a = rev_a;
}

void	change_rev_rotate(t_list *cur, int s_a, int s_b)
{
	int	rev_a;
	int	rev_b;

	rev_a = s_a - cur->flg_rot_a;
	rev_b = s_b - cur->flg_rot_b;
	if (rev_a > rev_b)
	{
		if (rev_a < cur->flg_ready)
			change_value_ready(cur, rev_a, rev_b, rev_a);
	}
	else
	{
		if (rev_b < cur->flg_ready)
			change_value_ready(cur, rev_a, rev_b, rev_b);
	}
}

static void	change_value(int *rot, int *flg, int n, int f)
{
	*rot = n;
	*flg = f;
}

void	change_another_rotate(t_list *cur, int s_a, int s_b)
{
	int		rot_a;
	int		rot_b;
	int		flg_a;
	int		flg_b;

	rot_a = cur->rot_a;
	rot_b = cur->rot_b;
	flg_a = (int)cur->flg_rot_a;
	flg_b = (int)cur->flg_rot_b;
	if (s_a - cur->rot_a < cur->rot_a)
		change_value(&rot_a, &flg_a, s_a - cur->rot_a, 1 - cur->flg_rot_a);
	if (s_b - cur->rot_b < cur->rot_b)
		change_value(&rot_b, &flg_b, s_b - cur->rot_b, 1 - cur->flg_rot_b);
	if (flg_b != flg_a && rot_b + rot_a < cur->flg_ready)
	{
		cur->flg_rot_a = (char)flg_a;
		cur->flg_rot_b = (char)flg_b;
		cur->rot_a = rot_a;
		cur->rot_b = rot_b;
		cur->flg_ready = rot_b + rot_a;
	}
}
