/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:30:48 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:21:42 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			index;

	temp = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if ((unsigned char)*temp == (unsigned char)c)
			return ((void *)temp);
		temp++;
		index++;
	}
	return (0);
}
