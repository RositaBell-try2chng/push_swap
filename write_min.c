/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_0(t_list *adr, t_min *min)
{
	t_min	tmp;

	tmp.min1 = min->min0;
	tmp.min2 = min->min1;
	tmp.min3 = min->min2;
	tmp.min4 = min->min3;
	min->min0 = adr;
	min->min1 = tmp.min1;
	min->min2 = tmp.min2;
	min->min3 = tmp.min3;
	min->min4 = tmp.min4;
}

static void	case_1(t_list *adr, t_min *min)
{
	t_min	tmp;

	tmp.min2 = min->min1;
	tmp.min3 = min->min2;
	tmp.min4 = min->min3;
	min->min1 = adr;
	min->min2 = tmp.min2;
	min->min3 = tmp.min3;
	min->min4 = tmp.min4;
}

static void	case_2(t_list *adr, t_min *min, char flg)
{
	t_min	tmp;

	if (flg == 2)
	{
		tmp.min3 = min->min2;
		tmp.min4 = min->min3;
		min->min2 = adr;
		min->min3 = tmp.min3;
		min->min4 = tmp.min4;
	}
	else
	{
		tmp.min4 = min->min3;
		min->min3 = adr;
		min->min4 = tmp.min4;
	}
}

static void	case_3(t_min *min)
{
	if (min->min1 == min->min0)
		min->min1 = NULL;
	else if (min->min2 == min->min0 || min->min2 == min->min1)
		min->min2 = NULL;
	else if (min->min3 == min->min0 || min->min3 == min->min1 || \
	min->min3 == min->min2)
		min->min3 = NULL;
	else if (min->min4 == min->min0 || min->min4 == min->min1 || \
	min->min4 == min->min2 || min->min4 == min->min3)
		min->min4 = NULL;
}

void	rewrite_minimal(t_list *adr, t_min *min, char flg)
{
	if (flg == 0)
		case_0(adr, min);
	else if (flg == 1)
		case_1(adr, min);
	else if (flg == 2 || flg == 3)
		case_2(adr, min, flg);
	else
		case_3(min);
}
