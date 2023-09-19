/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:15:07 by seungjpa          #+#    #+#             */
/*   Updated: 2023/07/28 17:15:19 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	if (stacks->b->size == 0)
		return ;
	if (stacks->a->size == 0)
	{
		stacks->a->head = stacks->b->head;
		stacks->a->tail = stacks->b->head;
		stacks->b->head = stacks->b->head->next;
		stacks->b->head->prev = NULL;
		stacks->a->head->next = NULL;
	}
	else
	{
		stacks->a->head->prev = stacks->b->head;
		if (stacks->b->size == 1)
			init_info(stacks->b);
		else
		{
			stacks->b->head = stacks->b->head->next;
			stacks->b->head->prev = NULL;
		}
		stacks->a->head->prev->next = stacks->a->head;
		stacks->a->head = stacks->a->head->prev;
	}
	change_size(stacks, 1, -1);
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	if (stacks->a->size == 0)
		return ;
	if (stacks->b->size == 0)
	{
		stacks->b->head = stacks->a->head;
		stacks->b->tail = stacks->a->head;
		stacks->a->head = stacks->a->head->next;
		stacks->a->head->prev = NULL;
		stacks->b->head->next = NULL;
	}
	else
	{
		stacks->b->head->prev = stacks->a->head;
		if (stacks->a->size == 1)
			init_info(stacks->a);
		else
		{
			stacks->a->head = stacks->a->head->next;
			stacks->a->head->prev = NULL;
		}
		stacks->b->head->prev->next = stacks->b->head;
		stacks->b->head = stacks->b->head->prev;
	}
	change_size(stacks, -1, 1);
	write(1, "pb\n", 3);
}
