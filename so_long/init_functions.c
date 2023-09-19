/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:15:34 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 14:13:27 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_count(t_count *count)
{
	count->p = 0;
	count->c = 0;
	count->e = 0;
	count->m = 0;
	count->player_c = 0;
}

void	init_map_info(t_map_info *map_info)
{
	map_info->map = NULL;
	map_info->width = 0;
	map_info->height = 0;
	init_count(&(map_info->count));
}

void	init_visited(t_map_info *map_info)
{
	int	count;
	int	count2;

	map_info->visited = malloc(sizeof(int *) * map_info->height);
	count = 0;
	while (count < map_info->height)
	{
		map_info->visited[count] = malloc(sizeof(int) * map_info->width - 1);
		count2 = 0;
		while (count2 < map_info->width - 1)
		{
			map_info->visited[count][count2] = 0;
			count2++;
		}
		count++;
	}
}
