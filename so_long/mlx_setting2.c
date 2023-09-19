/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:26:53 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 16:06:37 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_map_info *map_info, t_mlx_info *mlx_info)
{
	int	index1;
	int	index2;

	mlx_clear_window(mlx_info->mlx, mlx_info->win);
	index1 = 0;
	while (index1 < map_info->height)
	{
		index2 = 0;
		while (index2 < map_info->width - 1)
		{
			put_image(map_info, mlx_info, index1, index2);
			index2++;
		}
		index1++;
	}
}

int	close_game(void *param)
{
	(void)param;
	exit(0);
}
