/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:47:42 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 17:43:32 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	*protected_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		perror_and_exit();
	return (result);
}

void	ft_putnbr(int n)
{
	char	temp;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	temp = n % 10 + '0';
	write(1, &temp, 1);
	return ;
}
