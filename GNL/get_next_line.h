/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:04:28 by seungjpa          #+#    #+#             */
/*   Updated: 2023/06/29 01:12:56 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>

char	*re_allocate(char *arr, char *buf, int read_len, int total_len);
char	*copy_buf_to_result(char *buf, char *result);
char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, int n);
int		check_new_line(char *buf);
int		check_empty(char *str);

#endif