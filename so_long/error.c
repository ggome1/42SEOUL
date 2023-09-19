/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:02:29 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/13 17:43:35 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_err(void)
{
	write(1, "Map Error\n", 10);
	exit (0);
}

void	perror_and_exit(void)
{
	perror("Error\n");
	exit(1);
}
