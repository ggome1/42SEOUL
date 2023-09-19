/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:54:15 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/18 16:59:08 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*res_arr;
	unsigned int	index;

	len = ft_strlen(s);
	res_arr = malloc(sizeof(char) * (len + 1));
	if (res_arr == 0)
		return (0);
	index = 0;
	while (s[index])
	{
		res_arr[index] = f(index, s[index]);
		index++;
	}
	res_arr[index] = 0;
	return (res_arr);
}
