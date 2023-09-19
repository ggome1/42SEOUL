/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:48:28 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/21 17:45:01 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
