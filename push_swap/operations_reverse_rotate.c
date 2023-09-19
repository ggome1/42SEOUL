/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:20:55 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:02:49 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->a->size == 0 || stacks->a->size == 1)
		return ;
	stacks->a->head->prev = stacks->a->tail;
	stacks->a->head->prev->next = stacks->a->head;
	stacks->a->head = stacks->a->head->prev;
	stacks->a->tail = stacks->a->tail->prev;
	stacks->a->head->prev = NULL;
	stacks->a->tail->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	if (stacks->b->size == 0 || stacks->b->size == 1)
		return ;
	stacks->b->head->prev = stacks->b->tail;
	stacks->b->head->prev->next = stacks->b->head;
	stacks->b->head = stacks->b->head->prev;
	stacks->b->tail = stacks->b->tail->prev;
	stacks->b->head->prev = NULL;
	stacks->b->tail->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	write(1, "rrr\n", 4);
}
