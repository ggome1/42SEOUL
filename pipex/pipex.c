/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:51:44 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:28:42 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		error_and_exit();
	if (pipe(fd) == -1)
		perror_and_exit("pipe()");
	pid = fork();
	if (pid != 0)
		parent_process(fd, argv, env);
	if (pid == 0)
		child_process(fd, argv, env);
}
