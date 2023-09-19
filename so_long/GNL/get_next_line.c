/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:04:27 by seungjpa          #+#    #+#             */
/*   Updated: 2023/08/11 17:29:24 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_allocate(char *arr, char *buf, int read_len, int total_len)
{
	char	*new_arr;
	int		last_len;

	last_len = total_len - read_len;
	new_arr = malloc(sizeof(char) * (total_len + 1));
	if (new_arr == 0)
	{
		free(arr);
		exit(1);
	}
	if (arr == 0)
		ft_strncpy(new_arr, buf, total_len);
	else
	{
		ft_strncpy(new_arr, arr, last_len);
		ft_strncpy(new_arr + last_len, buf, read_len);
		free(arr);
	}
	new_arr[total_len] = '\0';
	return (new_arr);
}

char	*copy_buf_to_result(char *buf, char *result)
{
	int	add_len;
	int	existing_len;
	int	new_buf_index;

	add_len = 0;
	while (buf[add_len] != '\n' && buf[add_len] != '\0')
		add_len++;
	if (buf[add_len] == '\n')
		add_len++;
	existing_len = 0;
	if (result != 0)
	{
		while (result[existing_len] != 0)
			existing_len++;
	}
	result = re_allocate(result, buf, add_len, existing_len + add_len);
	if (result == 0)
		return (0);
	new_buf_index = 0;
	while (buf[add_len] != '\0')
		buf[new_buf_index++] = buf[add_len++];
	while (buf[new_buf_index] != '\0')
		buf[new_buf_index++] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*result;
	int				read_len;

	if (fd == -1)
		return (0);
	result = NULL;
	while (!check_new_line(result))
	{
		if (check_empty(buf))
		{
			read_len = read(fd, buf, BUFFER_SIZE);
			buf[read_len] = '\0';
		}
		if (read_len == -1)
		{
			if (result != 0)
				free(result);
			exit(1);
		}
		if (read_len == 0 && !check_new_line(buf))
			break ;
		result = copy_buf_to_result(buf, result);
	}
	return (result);
}
