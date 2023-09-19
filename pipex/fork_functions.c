/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:51:44 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/14 19:34:23 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *command, char **path, char **temp_path)
{
	int		index2;
	char	*save_path;

	index2 = -1;
	while (path[++index2])
	{
		save_path = ft_strjoin(path[index2], "/");
		if (save_path == 0)
			perror_and_exit("malloc()");
		*temp_path = ft_strjoin(save_path, command);
		if (*temp_path == 0)
		{
			free(save_path);
			perror_and_exit("malloc()");
		}
		if (access(*temp_path, F_OK) == 0)
			return (1);
	}
	return (0);
}

void	check_path(char *command, char **env, char **temp_path)
{
	int		index;
	char	**path;

	index = -1;
	if (access(command, F_OK) == 0)
	{
		*temp_path = command;
		return ;
	}
	while (env[++index])
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
		{
			path = ft_split(&env[index][5], ':');
			if (path == 0)
				perror_and_exit(command);
			if (check_access(command, path, temp_path))
				return ;
		}
	}
	command_err(command);
}

void	parent_process(int *fd, char **argv, char **env)
{
	int		fd_argv1;
	char	**first_command;
	char	*path;

	close(fd[0]);
	fd_argv1 = open(argv[1], O_RDONLY);
	if (fd_argv1 == -1)
		perror_and_exit(argv[1]);
	dup2(fd_argv1, 0);
	dup2(fd[1], 1);
	first_command = ft_split(argv[2], ' ');
	if (first_command == 0)
		perror_and_exit("malloc()");
	check_path(first_command[0], env, &path);
	execve(path, first_command, env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int		fd_argv2;
	char	**second_command;
	char	*path;

	close(fd[1]);
	fd_argv2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_argv2 == -1)
		perror_and_exit(argv[4]);
	dup2(fd[0], 0);
	dup2(fd_argv2, 1);
	second_command = ft_split(argv[3], ' ');
	if (second_command == 0)
		perror_and_exit("malloc");
	check_path(second_command[0], env, &path);
	execve(path, second_command, env);
}
