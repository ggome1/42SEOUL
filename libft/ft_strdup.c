/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:53:16 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:43:22 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		index;
	char	*dup;

	index = 0;
	while (src[index])
		index++;
	dup = (char *)malloc(sizeof(char) * (index + 1));
	if (dup == 0)
		return (0);
	index = 0;
	while (src[index])
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}
