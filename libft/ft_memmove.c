/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:45:38 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:31:13 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			count;

	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst == 0 && temp_src == 0)
		return (0);
	if (dst > src)
	{
		while (len--)
			temp_dst[len] = temp_src[len];
	}
	else
	{
		count = 0;
		while (count < len)
		{
			temp_dst[count] = temp_src[count];
			count++;
		}
	}
	return (dst);
}
