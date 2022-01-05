/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (--argc < 1)
		return (0);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	if (!a || !b)
		exit_program(a, b, 1);
	*a = NULL;
	*b = NULL;
	parse_argv(argc, &(argv[1]), a, b);
	if (argc == 1)
		return (0);
	if (argc <= 6)
		small_sort(a, b, argc);
	else
		big_sort(a, b, argc);
	exit_program(a, b, 0);
}

void	exit_program(t_list **a, t_list **b, char flg)
{
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	if (flg)
		write(2, "ERROR\n", 6);
	exit(0);
}
