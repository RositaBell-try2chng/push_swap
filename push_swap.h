/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbell <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:34:13 by rbell             #+#    #+#             */
/*   Updated: 2021/12/09 11:34:18 by rbell            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				n;
	int				i;
	char			flg_last;
	int				flg_ready;
	char			flg_max;
	char			flg_min;
	char			flg_rot_a;
	char			flg_rot_b;
	int				rot_a;
	int				rot_b;
	int				min_cnt;
	char			flg_stack;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_min
{
	t_list	*min0;
	t_list	*min1;
	t_list	*min2;
	t_list	*min3;
	t_list	*min4;
}	t_min;

void	parse_argv(int argc, char **argv, t_list **a, t_list **b);
void	exit_program(t_list **a, t_list **b, char flg);
void	big_sort(t_list **a, t_list **b, int argc);
void	small_sort(t_list **a, t_list **b, int argc);
t_list	*ft_lstnew(int n);
char	add_new_elem(t_list **a, int new, int i);
void	connect_first_last(t_list **a);
void	free_list(t_list **lst);
void	swap(t_list **lst, char name_stack);
void	swap_swap(t_list **a, t_list **b);
void	push(t_list	**dst, t_list **src, char name_stack);
void	rotate(t_list **lst, char name_stack);
void	rotate_rotate(t_list **a, t_list **b);
void	rev_rotate(t_list **lst, char name_stack);
void	reverse_reverse(t_list **a, t_list **b);
void	transform_numbers(t_list **a);
void	rewrite_minimal(t_list *adr, t_min *min, char flg);
void	sort_list(t_list **t, char name_stack, int size);
int		count_min_index(t_list **a);
int		count_max_index(t_list **a);
int		count_great(t_list **a);
int		count_great_rev(t_list **a);
void	index_sort(t_list **a);
void	index_rev_sort(t_list **a, int argc);
void	gr_th_rev_sort(t_list **a);
void	gr_th_sort(t_list **a);
void	push_b_2_b(t_list **a, t_list **b);
void	count_moves_for_put(t_list **a, t_list **b, int s_a, int s_b);
t_list	*find_minimal(t_list **b, int size);
void	do_it_for_min(t_list **a, t_list **b, t_list *min);
void	change_rev_rotate(t_list *cur, int s_a, int s_b);
void	change_another_rotate(t_list *cur, int s_a, int s_b);
#endif
