/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:15:50 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 18:45:54 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_arr;
	int		result_index;
	int		cur_index;

	result_arr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result_arr == 0)
		return (0);
	result_index = 0;
	cur_index = 0;
	while (s1[cur_index])
		result_arr[result_index++] = s1[cur_index++];
	cur_index = 0;
	while (s2[cur_index])
		result_arr[result_index++] = s2[cur_index++];
	result_arr[result_index] = 0;
	return (result_arr);
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
