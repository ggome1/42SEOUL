/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:22:29 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/26 18:09:56 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_int(int argc, char **argv)
{
	int	index1;
	int	index2;

	index1 = 1;
	while (index1 < argc)
	{
		index2 = 0;
		if (argv[index1][index2] == '-')
		{
			if (argv[index1][index2 + 1] == 0)
				return (0);
			index2++;
		}
		while (argv[index1][index2])
		{
			if (argv[index1][index2] < '0' || argv[index1][index2] > '9')
				return (0);
			index2++;
		}
		index1++;
	}
	return (1);
}

int	check_is_duplication(int argc, int *argv)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < argc)
	{
		index2 = index1 + 1;
		while (index2 < argc)
		{
			if (argv[index1] == argv[index2])
				return (1);
			index2++;
		}
		index1++;
	}
	return (0);
}

int	check_is_already_sorted(int argc, int *argv)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (argv[index] > argv[index + 1])
			return (0);
		index++;
	}
	return (1);
}

void	print_err(int err_type)
{
	if (err_type == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	exit(1);
}
