/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:15:16 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/26 17:10:37 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_node *node)
{
	node->prev = NULL;
	node->next = NULL;
}

void	init_info(t_list_info *list_info)
{
	list_info->head = NULL;
	list_info->tail = NULL;
}

void	add_node(t_stacks *stacks, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == 0)
		exit(1);
	init_node(new_node);
	new_node->value = value;
	if (stacks->a->head == NULL)
	{
		stacks->a->head = new_node;
		stacks->a->tail = new_node;
	}
	else
	{
		stacks->a->tail->next = new_node;
		stacks->a->tail->next->prev = stacks->a->tail;
		stacks->a->tail = stacks->a->tail->next;
	}
	stacks->a->size += 1;
}

void	set_a(t_stacks *stacks, int argc, int *argv)
{
	int	count;

	count = 0;
	while (count < argc)
		add_node(stacks, argv[count++]);
}

void	set_init(t_stacks *stacks)
{
	t_list_info	*info_a;
	t_list_info	*info_b;

	info_a = malloc(sizeof(t_list_info));
	if (info_a == NULL)
		exit(1);
	info_b = malloc(sizeof(t_list_info));
	if (info_b == NULL)
		exit(1);
	init_info(info_a);
	info_a->size = 0;
	init_info(info_b);
	info_b->size = 0;
	stacks->a = info_a;
	stacks->b = info_b;
}
