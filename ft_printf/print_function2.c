/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:19:23 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/26 15:00:10 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_u(unsigned int num, int *len)
{
	char	temp;

	if (num / 10 != 0)
	{
		if (print_u(num / 10, len) == -1)
			return (-1);
	}
	temp = num % 10 + '0';
	if (write(1, &temp, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}

void	put_save(char *save, int num, int i, char *base)
{
	unsigned int	unum;

	unum = (unsigned int)num;
	while (unum >= 16 && i)
	{
		save[i] = base[unum % 16];
		unum /= 16;
		i--;
	}
	save[i--] = base[unum % 16];
	return ;
}

int	print_x(int num, int *len)
{
	char	save[9];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*len)++;
	}
	i = 0;
	while (i < 8)
		save[i++] = '0';
	put_save(save, num, 7, base);
	i = 0;
	while (save[i] == '0' && i < 8)
			i++;
	while (i < 8)
	{
		if (write(1, &save[i++], 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_upper_x(int num, int *len)
{
	char	save[9];
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*len)++;
	}
	i = 0;
	while (i < 8)
		save[i++] = '0';
	put_save(save, num, 7, base);
	i = 0;
	while (save[i] == '0' && i < 8)
			i++;
	while (i < 8)
	{
		if (write(1, &save[i++], 1) == -1)
			return (-1);
		(*len)++;
	}
	return (0);
}

int	print_37(int *len)
{
	int	c;

	c = 37;
	if (write(1, &c, 1) == -1)
		return (-1);
	(*len)++;
	return (0);
}
