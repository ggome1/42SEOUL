/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:13:21 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/19 17:28:28 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_and_exit(void)
{
	write(1, "ERROR!\n", 7);
}

void	perror_and_exit(char *file_name)
{
	char	*name;

	name = ft_strjoin("bash: ", file_name);
	perror(name);
	exit(1);
}

void	command_err(char *command)
{
	write(2, "pipex: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": command not found\n", 20);
}
