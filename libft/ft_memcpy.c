/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:34:43 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:29:05 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			count;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == 0 && temp_src == 0)
		return (0);
	count = 0;
	while (count < n)
	{
		*temp_dst++ = *temp_src++;
		count++;
	}
	return (dst);
}
