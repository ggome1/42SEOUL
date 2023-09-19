/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:46:10 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:48:35 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	srcsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	count = 0;
	while (count < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		count++;
	}
	*dst = 0;
	return (srcsize);
}
