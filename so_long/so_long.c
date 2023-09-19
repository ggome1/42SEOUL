/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:07:47 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 16:05:27 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		map_err();
	check_map(argv[1], &info.map_info);
	info.mlx_info.mlx = mlx_init();
	info.mlx_info.win = mlx_new_window(info.mlx_info.mlx,
			(info.map_info.width - 1) * 64,
			info.map_info.height * 64, "so_long");
	mlx_key_hook(info.mlx_info.win, &press_key, &info);
	mlx_hook(info.mlx_info.win, 17, 0, &close_game, 0);
	save_image(&info.mlx_info);
	render_image(&info.map_info, &info.mlx_info);
	mlx_loop(info.mlx_info.mlx);
}
