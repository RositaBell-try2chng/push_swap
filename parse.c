/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *str, char *flg)
{
	size_t	i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = -1;
	if (str[i + 1] == 45)
		sign = -1;
	if (str[i + 1] == 45 || str[i + 1] == 43)
		i++;
	while (str[++i] > 47 && str[i] < 58)
	{
		res = (res * 10) + str[i] - '0';
		if ((res - 1 > INT_MAX) || (res > INT_MAX && sign > 0))
			*flg = 0;
	}
	if (str[i] != 0)
		*flg = 0;
	return ((int)(res * sign));
}

static char	check_uniq(int n, int i, char *f_sort, int argc)
{
	static int	*values;

	(void )*f_sort;
	if (i == 0)
	{
		values = malloc(sizeof(int) * argc);
		if (!values)
			return (0);
		values[i] = n;
		return (1);
	}
	if (i == -1 && argc == -1)
	{
		free(values);
		return (1);
	}
	if (*f_sort && n < values[i - 1])
		*f_sort = 0;
	values[i] = n;
	while (--i >= 0)
	{
		if (n == values[i])
			return (0);
	}
	return (1);
}

void	parse_argv(int argc, char **argv, t_list **a, t_list **b)
{
	int		new;
	int		i;
	char	f_correct;
	char	flg_sort;

	i = -1;
	f_correct = 1;
	flg_sort = 1;
	while (++i < argc && f_correct)
	{
		new = ft_atoi(argv[i], &f_correct);
		if (f_correct && !check_uniq(new, i, &flg_sort, argc))
			f_correct = 0;
		else if (!add_new_elem(a, new, i))
			f_correct = 0;
	}
	check_uniq(new, -1, &flg_sort, -1);
	if (!f_correct)
		exit_program(a, b, 1);
	if (flg_sort)
		exit_program(a, b, 0);
	connect_first_last(a);
}
