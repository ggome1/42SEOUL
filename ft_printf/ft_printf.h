/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:24:38 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/26 15:05:40 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_c(int c, int *len);
int	print_s(char *str, int *len);
int	print_p(void *str, int *len);
int	print_d(int num, int *len);
int	print_i(int num, int *len);
int	print_u(unsigned int num, int *len);
int	print_x(int num, int *len);
int	print_upper_x(int num, int *len);
int	print_37(int *len);

#endif