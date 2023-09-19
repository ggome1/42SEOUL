/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:52:05 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:27:40 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_wid_hei(t_map_info *map_info)
{
	int	count;
	int	len;

	map_info->width = ft_strlen(map_info->map[0]);
	count = 1;
	while (map_info->map[count])
	{
		len = ft_strlen(map_info->map[count]);
		if (map_info->map[count][len - 1] != '\n')
		{
			if (len != map_info->width - 1)
				map_err();
		}
		else
			if (len != map_info->width)
				map_err();
		count++;
	}
}

void	mem_realloc(t_map_info *map_info)
{
	char	**temp_map;
	int		count;

	if (map_info->map == NULL)
	{
		map_info->map = protected_malloc(sizeof(int *) * 2);
		map_info->map[1] = NULL;
	}
	else
	{
		temp_map = map_info->map;
		map_info->map = protected_malloc(sizeof(int *)
				* (map_info->height + 1));
		map_info->map[map_info->height] = NULL;
		count = 0;
		while (count < map_info->height - 1)
		{
			map_info->map[count] = temp_map[count];
			count++;
		}
		free(temp_map);
	}
}

void	change_map(char *map_name, t_map_info *map_info)
{
	int		fd;
	char	*temp_line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		map_err();
	while (1)
	{
		temp_line = get_next_line(fd);
		if (temp_line == 0)
			break ;
		map_info->height++;
		mem_realloc(map_info);
		map_info->map[map_info->height - 1] = temp_line;
	}
	close(fd);
}

void	check_count(t_map_info *map_info)
{
	int	index1;
	int	index2;

	index1 = 0;
	while (++index1 < map_info->height)
	{
		index2 = 0;
		while (++index2 < map_info->width - 1)
		{
			if (map_info->map[index1][index2] == 'P')
			{
				map_info->coord.i = index1;
				map_info->coord.j = index2;
				map_info->count.p++;
			}
			if (map_info->map[index1][index2] == 'E')
				map_info->count.e++;
			if (map_info->map[index1][index2] == 'C')
				map_info->count.c++;
		}
	}
	if (map_info->count.p != 1 || map_info->count.c < 1
		|| map_info->count.e != 1)
		map_err();
}

void	check_map(char *map_name, t_map_info *map_info)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] != '.' || map_name[len - 3] != 'b'
		|| map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
		map_err();
	init_map_info(map_info);
	change_map(map_name, map_info);
	check_map_wid_hei(map_info);
	check_surrounded_1(map_info);
	check_count(map_info);
	valid_path_check(map_info);
	map_info->map[map_info->coord.i][map_info->coord.j] = '0';
}
