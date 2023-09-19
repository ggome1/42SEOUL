/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:01:58 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:14:46 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}		t_node;

typedef struct s_list_info
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}		t_list_info;

typedef struct s_stacks
{
	t_list_info	*a;
	t_list_info	*b;
}		t_stacks;

typedef struct s_sort_info
{
	int	count_a;
	int	count_b;
	int	total;
}		t_sort_info;

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

int		check_is_int(int argc, char **argv);
int		check_is_duplication(int argc, int *argv);
int		check_is_already_sorted(int argc, int *argv);
void	print_err(int err_type);

int		ft_atoi(const char *str);
int		*change_argv_to_int(int argc, char **argv);
void	change_size(t_stacks *stacks, int a, int b);
int		abs_num(int num);

void	init_sort_info(t_sort_info *sort_info);
void	init_node(t_node *node);
void	init_info(t_list_info *list_info);
void	add_node(t_stacks *stacks, int value);
void	set_a(t_stacks *stacks, int argc, int *argv);
void	set_init(t_stacks *stacks);

void	sort_int_arr(int *new_int_argv, int size);
void	hard_cording_ascending_3(t_stacks *stacks, t_list_info *which);
void	pivot_sort(t_stacks *stacks, int pivot, int argc);
void	hard_cording(t_stacks *stacks, int argc, int *new_int_argv);

void	first_sort(t_stacks *stacks, int *new_int_argv, int argc);
int		find_count(int max, int min, t_node *temp_node);
int		find_min_in_a(t_stacks *stacks, t_node *temp_b);
void	find_min(t_stacks *stacks, t_sort_info *sort_info);
void	do_sort(t_stacks *stacks, int *new_int_argv, int argc);
void	final_sort(t_stacks *stacks);

#endif