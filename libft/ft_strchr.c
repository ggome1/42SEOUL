/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:44:00 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:40:08 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*temp_s;

	temp_s = (unsigned char *)s;
	c = c % 256;
	while (*temp_s)
	{
		if (*temp_s == c)
			return ((char *)temp_s);
		temp_s++;
	}
	if (c == 0)
		return ((char *)temp_s);
	return (0);
}
