/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:09:25 by seungjpa          #+#    #+#             */
/*   Updated: 2023/07/28 18:00:38 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += sign * (*str - '0');
		str++;
	}
	if (result > 2147483647 || result < -2147483648)
		print_err(0);
	return ((int)result);
}

int	*change_argv_to_int(int argc, char **argv)
{
	int			*new_argv;
	long long	jud_int;
	int			index;

	index = 1;
	new_argv = malloc(sizeof(int) * (argc - 1));
	while (index < argc)
	{
		jud_int = ft_atoi(argv[index]);
		new_argv[index - 1] = jud_int;
		index++;
	}
	return (new_argv);
}

void	change_size(t_stacks *stacks, int a, int b)
{
	stacks->a->size += a;
	stacks->b->size += b;
}

int	abs_num(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
