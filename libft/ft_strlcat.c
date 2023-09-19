/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:05:13 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/13 22:06:35 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	save_dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	save_dest_len = dest_len;
	while (src[src_len])
		src_len++;
	if (size < dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] != 0 && dest_len + 1 < size)
		dest[dest_len++] = src[i++];
	dest[dest_len] = 0;
	return (save_dest_len + src_len);
}
