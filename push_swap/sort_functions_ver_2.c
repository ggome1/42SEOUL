/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_ver_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:59:24 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:03:22 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_count(int max, int min, t_node *temp_node)
{
	int	count;

	count = 0;
	if (max == 2147483647)
	{
		while (temp_node)
		{
			if (temp_node->value == min)
				return (count);
			count++;
			temp_node = temp_node->next;
		}
	}
	else
	{
		while (temp_node)
		{
			if (temp_node->value == max)
				return (count);
			count++;
			temp_node = temp_node->next;
		}
	}
	return (0);
}

int	find_min_in_a(t_stacks *stacks, t_node *temp_b)
{
	int		max;
	int		min;
	t_node	*temp_node;

	if (stacks->a->size == 0)
		return (0);
	temp_node = stacks->a->head;
	max = 2147483647;
	min = 2147483647;
	while (temp_node)
	{
		if (temp_node->value > temp_b->value && temp_node->value < max)
			max = temp_node->value;
		if (temp_node->value < min)
			min = temp_node->value;
		temp_node = temp_node->next;
	}
	temp_node = stacks->a->head;
	return (find_count(max, min, temp_node));
}

void	find_min(t_stacks *stacks, t_sort_info *sort_info)
{
	int		index;
	t_node	*temp_node;
	int		temp_a;
	int		temp_b;

	temp_node = stacks->b->head;
	index = 0;
	while (index < stacks->b->size)
	{
		temp_a = find_min_in_a(stacks, temp_node);
		if (temp_a != 0 && temp_a > (stacks->a->size) / 2)
			temp_a = (stacks->a->size - temp_a) * (-1);
		temp_b = index;
		if (temp_b != 0 && temp_b > (stacks->b->size) / 2)
			temp_b = (stacks->b->size - index) * (-1);
		if (index == 0 || abs_num(temp_a) + abs_num(temp_b) < sort_info->total)
		{
			sort_info->total = abs_num(temp_a) + abs_num(temp_b);
			sort_info->count_a = temp_a;
			sort_info->count_b = temp_b;
		}
		index++;
		temp_node = temp_node->next;
	}
}

void	final_sort(t_stacks *stacks)
{
	int		count;
	t_node	*temp;

	temp = stacks->a->head->next;
	count = 0;
	while (temp && temp->prev->value < temp->value)
	{
		count++;
		temp = temp->next;
	}
	count++;
	if (count > stacks->a->size / 2)
	{
		count = stacks->a->size - count;
		while (count--)
			rra(stacks);
	}
	else
	{
		while (count--)
			ra(stacks);
	}
}

void	do_sort(t_stacks *stacks, int *new_int_argv, int argc)
{
	t_sort_info	sort_info;

	first_sort(stacks, new_int_argv, argc);
	while (stacks->b->size)
	{
		init_sort_info(&sort_info);
		find_min(stacks, &sort_info);
		if (sort_info.count_b > 0)
			while (sort_info.count_b--)
				rb(stacks);
		else
			while (sort_info.count_b++)
				rrb(stacks);
		if (sort_info.count_a > 0)
			while (sort_info.count_a--)
				ra(stacks);
		else
			while (sort_info.count_a++)
				rra(stacks);
		pa(stacks);
	}
	final_sort(stacks);
}
