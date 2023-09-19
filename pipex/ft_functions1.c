/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:30:51 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 18:46:32 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_arr(char const *str, char charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != charset)
		{
			count++;
			while (*str != charset && *str)
				str++;
		}
		else
			str++;
	}
	return (count);
}

int	assign(char const *str, char charset, char **bound)
{
	int	count;
	int	i;

	count = 0;
	while (str[count] != charset && str[count])
		count++;
	*bound = malloc(sizeof(char) * (count + 1));
	if (*bound == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		(*bound)[i] = str[i];
		i++;
	}
	(*bound)[i] = 0;
	return (count);
}

void	mal_free(char **bound, int index)
{
	int	count;

	if (index == 0)
		return ;
	count = 0;
	while (count < index)
		free(bound[count++]);
	return ;
}

int	work(char const *str, char charset, char **bound)
{
	int	index;
	int	count_assign;

	index = 0;
	while (*str)
	{
		if (*str != charset)
		{
			count_assign = assign(str, charset, &bound[index]);
			if (count_assign == 0)
			{
				mal_free(bound, index);
				free(bound);
				return (0);
			}
			str += count_assign;
			index++;
		}
		else
			str++;
	}
	bound[index] = 0;
	return (1);
}

char	**ft_split(char const *str, char charset)
{
	char	**bound;

	bound = malloc(sizeof(char *) * (count_arr(str, charset) + 1));
	if (bound == 0)
		return (0);
	if (!(work(str, charset, bound)))
		return (0);
	return (bound);
}
