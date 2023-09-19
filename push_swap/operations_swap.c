/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:13:45 by seungjpa          #+#    #+#             */
/*   Updated: 2023/07/28 16:35:47 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->a->size == 0)
		return ;
	temp = stacks->a->head->value;
	stacks->a->head->value = stacks->a->head->next->value;
	stacks->a->head->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->b->size == 0)
		return ;
	temp = stacks->b->head->value;
	stacks->b->head->value = stacks->b->head->next->value;
	stacks->b->head->next->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	write(1, "ss\n", 3);
}
