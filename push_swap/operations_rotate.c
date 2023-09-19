/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:15:33 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:02:09 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->a->size == 0 || stacks->a->size == 1)
		return ;
	stacks->a->tail->next = stacks->a->head;
	stacks->a->tail->next->prev = stacks->a->tail;
	stacks->a->tail = stacks->a->tail->next;
	stacks->a->head = stacks->a->head->next;
	stacks->a->tail->next = NULL;
	stacks->a->head->prev = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	if (stacks->b->size == 0 || stacks->b->size == 1)
		return ;
	stacks->b->tail->next = stacks->b->head;
	stacks->b->tail->next->prev = stacks->b->tail;
	stacks->b->tail = stacks->b->tail->next;
	stacks->b->head = stacks->b->head->next;
	stacks->b->tail->next = NULL;
	stacks->b->head->prev = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
	write(1, "rr\n", 3);
}
