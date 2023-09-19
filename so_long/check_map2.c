/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:24:30 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 15:24:39 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_count *temp_count, int i, int j, t_map_info *map_info)
{
	if (map_info->map[i][j] == '1' || map_info->visited[i][j] == 1)
		return ;
	map_info->visited[i][j] = 1;
	if (map_info->map[i][j] == 'P')
		temp_count->p++;
	if (map_info->map[i][j] == 'C')
		temp_count->c++;
	if (map_info->map[i][j] == 'E')
		temp_count->e++;
	dfs(temp_count, i + 1, j, map_info);
	dfs(temp_count, i - 1, j, map_info);
	dfs(temp_count, i, j + 1, map_info);
	dfs(temp_count, i, j - 1, map_info);
}

void	valid_path_check(t_map_info *map_info)
{
	t_count	temp;

	init_visited(map_info);
	init_count(&temp);
	dfs(&temp, map_info->coord.i, map_info->coord.j, map_info);
	if (temp.p != map_info->count.p
		|| temp.e != map_info->count.e
		|| temp.c != map_info->count.c)
		map_err();
}

void	check_surrounded_1(t_map_info *map_info)
{
	int	index1;
	int	index2;

	index1 = -1;
	while (++index1 < map_info->height)
	{
		index2 = -1;
		while (++index2 < map_info->width - 1)
		{
			if ((index1 == 0 || index1 == map_info->height - 1)
				&& map_info->map[index1][index2] != '1')
				map_err();
			if ((index2 == 0 || index2 == map_info->width - 2)
				&& map_info->map[index1][index2] != '1')
				map_err();
		}
	}
}
