/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:21:04 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/17 17:37:28 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_info(t_sort_info *sort_info)
{
	sort_info->count_a = 0;
	sort_info->count_b = 0;
	sort_info->total = 0;
}

void	sort_int_arr(int *new_int_argv, int size)
{
	int	index;
	int	temp;

	while (--size)
	{
		index = 0;
		while (index < size)
		{
			if (new_int_argv[index] > new_int_argv[index + 1])
			{
				temp = new_int_argv[index];
				new_int_argv[index] = new_int_argv[index + 1];
				new_int_argv[index + 1] = temp;
			}
			index++;
		}
	}
}

void	first_sort(t_stacks *stacks, int *new_int_argv, int argc)
{
	int	pivot1;
	int	pivot2;

	pivot1 = new_int_argv[(stacks->a->size) / 3];
	pivot2 = new_int_argv[(stacks->a->size) / 3 * 2];
	while (argc--)
	{
		if (stacks->a->head->value < pivot1)
		{
			pb(stacks);
			rb(stacks);
		}
		else if (stacks->a->head->value > pivot2)
			ra(stacks);
		else
			pb(stacks);
	}
	while (stacks->a->size)
		pb(stacks);
}
