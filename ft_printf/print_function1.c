/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:19:26 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/26 14:42:47 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_c(int c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}

int	print_s(char *str, int *len)
{
	if (str == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*len += 6;
		return (0);
	}
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_p(void *str, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if ((unsigned long long)str < 16)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (write(1, &base[(unsigned long long)str % 16], 1) == -1)
			return (-1);
		*len += 3;
		return (0);
	}
	if (print_p((void *)((unsigned long long)str / 16), len) == -1)
		return (-1);
	if (write(1, &base[(unsigned long long)str % 16], 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}

int	print_d(int num, int *len)
{
	char	temp;

	if (num == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*len += 11;
		return (0);
	}
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*len)++;
		num *= -1;
	}
	if (num / 10 != 0)
		if (print_d(num / 10, len) == -1)
			return (-1);
	temp = num % 10 + '0';
	if (write(1, &temp, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}

int	print_i(int num, int *len)
{
	char	temp;

	if (num == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*len += 11;
		return (0);
	}
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*len)++;
		num *= -1;
	}
	if (num / 10 != 0)
		if (print_i(num / 10, len) == -1)
			return (-1);
	temp = num % 10 + '0';
	if (write(1, &temp, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}
