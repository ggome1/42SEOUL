/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:09:05 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:57:20 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	include_set(char const s1, char const *set)
{
	while ((*set))
	{
		if (s1 == *set++)
			return (1);
	}
	return (0);
}

static char	*empty_str_malloc(char *res_arr)
{
	res_arr = malloc(sizeof(char) * 1);
	if (res_arr == 0)
		return (0);
	res_arr[0] = 0;
	return (res_arr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	index;
	char	*res_arr;
	size_t	len_mal;

	res_arr = 0;
	if (ft_strlen(s1) == 0)
		return (empty_str_malloc(res_arr));
	len_s1 = ft_strlen(s1) - 1;
	index = 0;
	while (s1[index] && include_set(s1[index], set))
		index++;
	while (len_s1 > 0 && include_set(s1[len_s1], set))
		len_s1--;
	if (index > len_s1)
		return (empty_str_malloc(res_arr));
	else
		res_arr = malloc(sizeof(char) * (len_s1 - index + 2));
	if (res_arr == 0)
		return (0);
	len_mal = 0;
	while (index <= len_s1)
		res_arr[len_mal++] = s1[index++];
	res_arr[len_mal] = 0;
	return (res_arr);
}
