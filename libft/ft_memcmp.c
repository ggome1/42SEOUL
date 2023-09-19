/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:49:35 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:28:03 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			index;

	if (n == 0)
		return (0);
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	index = 0;
	while (++index != n)
	{
		if (*temp_s1 != *temp_s2)
		{
			return (*temp_s1 - *temp_s2);
		}
		temp_s1++;
		temp_s2++;
	}
	return (*temp_s1 - *temp_s2);
}
