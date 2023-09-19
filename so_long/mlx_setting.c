/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:03:51 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/23 17:16:50 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_image(t_mlx_info *mlx_info)
{
	int	width;
	int	height;

	mlx_info->wall_img = mlx_xpm_file_to_image(mlx_info->mlx,
			"./images/wall.xpm", &width, &height);
	mlx_info->player_img = mlx_xpm_file_to_image(mlx_info->mlx,
			"./images/player.xpm", &width, &height);
	mlx_info->exit_img = mlx_xpm_file_to_image(mlx_info->mlx,
			"./images/exit.xpm", &width, &height);
	mlx_info->coll_img = mlx_xpm_file_to_image(mlx_info->mlx,
			"./images/coll.xpm", &width, &height);
}

int	is_moved(int prev_i, int prev_j, int cur_i, int cur_j)
{
	if (prev_i != cur_i || prev_j != cur_j)
		return (1);
	return (0);
}

void	move_player(t_info *info)
{
	if (info->map_info.map[info->map_info.coord.i][info->map_info.coord.j]
		== 'C')
	{
		info->map_info.count.player_c++;
		info->map_info.map[info->map_info.coord.i][info->map_info.coord.j]
			= '0';
	}
	if (info->map_info.map[info->map_info.coord.i][info->map_info.coord.j]
		== 'E'
		&& info->map_info.count.c == info->map_info.count.player_c)
		exit(0);
}

int	press_key(int keycode, t_info *info)
{
	int	i;
	int	j;

	i = info->map_info.coord.i;
	j = info->map_info.coord.j;
	if (keycode == W && info->map_info.map[i - 1][j] != '1')
		info->map_info.coord.i--;
	if (keycode == S && info->map_info.map[i + 1][j] != '1')
		info->map_info.coord.i++;
	if (keycode == D && info->map_info.map[i][j + 1] != '1')
		info->map_info.coord.j++;
	if (keycode == A && info->map_info.map[i][j - 1] != '1')
		info->map_info.coord.j--;
	else if (keycode == ESC)
		exit(0);
	move_player(info);
	if (is_moved(i, j, info->map_info.coord.i, info->map_info.coord.j) == 1)
	{
		info->map_info.count.m++;
		ft_putnbr(info->map_info.count.m);
		write(1, "\n", 1);
	}
	render_image(&info->map_info, &info->mlx_info);
	return (0);
}

void	put_image(t_map_info *map_info, t_mlx_info *mlx_info, int i, int j)
{
	if (map_info->map[i][j] == '1')
		mlx_put_image_to_window(mlx_info->mlx, mlx_info->win,
			mlx_info->wall_img, 64 * j, 64 * i);
	else if (map_info->map[i][j] == 'C')
		mlx_put_image_to_window(mlx_info->mlx, mlx_info->win,
			mlx_info->coll_img, 64 * j, 64 * i);
	else if (map_info->map[i][j] == 'E')
		mlx_put_image_to_window(mlx_info->mlx, mlx_info->win,
			mlx_info->exit_img, 64 * j, 64 * i);
	mlx_put_image_to_window(mlx_info->mlx, mlx_info->win,
		mlx_info->player_img, 64 * map_info->coord.j, 64 * map_info->coord.i);
}
