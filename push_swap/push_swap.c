/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:01:33 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:25:51 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*new_int_argv;

	if (argc < 2)
		print_err(-1);
	if (!check_is_int(argc, argv))
		print_err(0);
	new_int_argv = change_argv_to_int(argc, argv);
	argc--;
	if (check_is_duplication(argc, new_int_argv))
		print_err(0);
	if (check_is_already_sorted(argc, new_int_argv))
		print_err(-1);
	set_init(&stacks);
	set_a(&stacks, argc, new_int_argv);
	sort_int_arr(new_int_argv, stacks.a->size);
	if (argc < 6)
		hard_cording(&stacks, argc, new_int_argv);
	else
		do_sort(&stacks, new_int_argv, argc);
	exit(0);
}
