/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:52:11 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/14 19:22:10 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

void	child_process(int *fd, char **argv, char **env);
void	parent_process(int *fd, char **argv, char **env);

void	perror_and_exit(char *file_name);
void	command_err(char *command);
void	error_and_exit(void);

int		count_arr(char const *str, char charset);
int		assign(char const *str, char charset, char **bound);
void	mal_free(char **bound, int index);
int		work(char const *str, char charset, char **bound);
char	**ft_split(char const *str, char charset);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);

int		check_access(char *command, char **path, char **temp_path);
void	check_path(char *command, char **env, char **temp_path);

#endif