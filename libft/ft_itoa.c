/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:37:43 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 18:04:01 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	numlen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result_arr;
	int			len_mal;
	long long	temp_n;

	temp_n = (long long)n;
	len_mal = numlen(temp_n);
	result_arr = malloc(sizeof(char) * (len_mal + 1));
	if (result_arr == 0)
		return (0);
	if (temp_n < 0)
	{
		result_arr[0] = '-';
		temp_n *= -1;
	}
	result_arr[len_mal] = 0;
	while (len_mal--)
	{
		if (n < 0 && len_mal == 0)
			break ;
		result_arr[len_mal] = temp_n % 10 + '0';
		temp_n /= 10;
	}
	return (result_arr);
}
