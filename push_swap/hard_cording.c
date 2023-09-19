/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_cording.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:21:04 by seungjpa          #+#    #+#             */
/*   Updated: 2023/07/28 20:09:16 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_cording_ascending_3(t_stacks *stacks, t_list_info *which)
{
	if (which->head->value > which->head->next->value)
		sa(stacks);
	if (which->head->next->value > which->head->next->next->value)
		rra(stacks);
	if (which->head->value > which->head->next->value)
		sa(stacks);
}

void	pivot_sort(t_stacks *stacks, int pivot, int argc)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		if (stacks->a->head->value <= pivot)
			pb(stacks);
		else
			ra(stacks);
		count++;
	}
}

void	hard_cording(t_stacks *stacks, int argc, int *new_int_argv)
{
	if (argc == 2)
		sa(stacks);
	else if (argc == 3)
		hard_cording_ascending_3(stacks, stacks->a);
	else if (argc == 4)
	{
		pivot_sort(stacks, new_int_argv[1], argc);
		if (stacks->a->head->value > stacks->a->head->next->value)
			sa(stacks);
		if (stacks->b->head->value < stacks->b->head->next->value)
			sb(stacks);
		pa(stacks);
		pa(stacks);
	}
	else
	{
		pivot_sort(stacks, new_int_argv[1], argc);
		hard_cording_ascending_3(stacks, stacks->a);
		if (stacks->b->head->value < stacks->b->head->next->value)
			sb(stacks);
		pa(stacks);
		pa(stacks);
	}
}
