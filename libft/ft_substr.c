/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:07:07 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 18:04:46 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static char	*empty_str_malloc(char *res_arr)
{
	res_arr = malloc(sizeof(char) * 1);
	if (res_arr == 0)
		return (0);
	res_arr[0] = 0;
	return (res_arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = 0;
	i = ft_strlen(s);
	if (i <= start)
		return (empty_str_malloc(str));
	if (i - start < len)
	{
		str = malloc(sizeof(char) * (i - start + 1));
		len = i - start;
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (i != 0)
	{
		i = 0;
		while (i < len)
			str[i++] = s[start++];
	}
	str[i] = 0;
	return (str);
}
