/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjpa <seungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:11:23 by seungjpa          #+#    #+#             */
/*   Updated: 2023/03/27 18:26:34 by seungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cmp_and_prt(const char format, va_list want, int *len)
{
	int	jud;

	jud = 0;
	if (format == 'c')
		jud += print_c(va_arg(want, int), len);
	else if (format == 's')
		jud += print_s(va_arg(want, char *), len);
	else if (format == 'p')
		jud += print_p(va_arg(want, void *), len);
	else if (format == 'd')
		jud += print_d(va_arg(want, int), len);
	else if (format == 'i')
		jud += print_i(va_arg(want, int), len);
	else if (format == 'u')
		jud += print_u(va_arg(want, unsigned int), len);
	else if (format == 'x')
		jud += print_x(va_arg(want, unsigned long long), len);
	else if (format == 'X')
		jud += print_upper_x(va_arg(want, unsigned long long), len);
	else if (format == '%')
		jud += print_37(len);
	if (jud == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	want;
	int		len;

	va_start(want, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				return (len);
			if (cmp_and_prt(*format, want, &len) == -1)
				return (-1);
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(want);
	return (len);
}
