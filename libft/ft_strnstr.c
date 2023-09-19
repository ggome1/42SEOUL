/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:33:44 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:53:09 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index_h;
	size_t	index_n;

	if (needle[0] == 0)
		return ((char *)haystack);
	index_h = 0;
	while (haystack[index_h] && index_h < len)
	{
		if (haystack[index_h] == needle[0])
		{
			index_n = 1;
			while (needle[index_n] && index_h + index_n < len)
			{
				if (haystack[index_h + index_n] != needle[index_n])
					break ;
				index_n++;
			}
			if (needle[index_n] == 0)
				return ((char *)&haystack[index_h]);
		}
		index_h++;
	}
	return (0);
}
