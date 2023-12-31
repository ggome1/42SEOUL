/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:07:14 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/16 19:02:18 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (!(*temp_s1 == 0 || *temp_s2 == 0) && --n)
	{
		if (*temp_s1 != *temp_s2)
			return (*temp_s1 - *temp_s2);
		else
		{
			temp_s1++;
			temp_s2++;
		}
	}
	return (*temp_s1 - *temp_s2);
}
