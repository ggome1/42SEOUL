/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:24:58 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 16:06:14 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# include "GNL/get_next_line.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_coord
{
	int	i;
	int	j;
}	t_coord;

typedef struct s_count
{
	int	player_c;
	int	c;
	int	p;
	int	e;
	int	m;
}	t_count;

typedef struct s_map_info
{
	char	**map;
	int		**visited;
	int		width;
	int		height;
	t_coord	coord;
	t_count	count;
}	t_map_info;

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	void	*exit_img;
	void	*coll_img;
}	t_mlx_info;

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_map_info	map_info;
}	t_info;

void	map_err(void);

void	init_count(t_count *count);
void	init_map_info(t_map_info *map_info);
void	init_visited(t_map_info *map_info);

void	check_map_wid_hei(t_map_info *map_info);
void	change_map(char *map_name, t_map_info *map_info);
void	check_count(t_map_info *map_info);
void	dfs(t_count *temp_count, int i, int j, t_map_info *map_info);
void	valid_path_check(t_map_info *map_info);
void	check_surrounded_1(t_map_info *map_info);
void	check_map(char *map_name, t_map_info *map_info);
void	mem_realloc(t_map_info *map_info);

int		ft_strlen(const char *s);
void	ft_putnbr(int n);
void	*protected_malloc(size_t size);
void	perror_and_exit(void);

void	save_image(t_mlx_info *mlx_info);
void	render_image(t_map_info *map_info, t_mlx_info *mlx_info);
void	put_image(t_map_info *map_info, t_mlx_info *mlx_info, int i, int j);
int		press_key(int keycode, t_info *map_info);
void	move_player(t_info *info);
int		is_moved(int prev_i, int prev_j, int cur_i, int cur_j);
int		close_game(void *param);
#endif