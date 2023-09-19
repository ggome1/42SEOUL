/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:04:24 by seungjpa          #+#    #+#             */
/*   Updated: 2023/06/19 21:51:02 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int		index;
	char	*original_dest;	

	original_dest = dest;
	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	return (original_dest);
}

int	check_new_line(char *str)
{
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	check_empty(char *str)
{
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != '\0')
			return (0);
		str++;
	}
	return (1);
}
