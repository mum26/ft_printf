/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:09:29 by sishige           #+#    #+#             */
/*   Updated: 2024/06/10 19:29:16 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_specifier(va_list ap, int c)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	else if (c == 's')
		return (print_str(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(ap, int)));
	else if (c == 'u')
		return (print_u_int(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex((unsigned int)va_arg(ap, int), ft_isupper(c)));
	else if (c == 'p')
		return (print_add(va_arg(ap, unsigned long long)));
	else if (c == '%')
		return (write(PRINT_FD, "%", 1));
	return (write(PRINT_FD, &c, 1));
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	int		len;
	int		tmp;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt++ == '%')
		{
			tmp = convert_specifier(ap, *fmt++);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else if (write(PRINT_FD, fmt - 1, 1) == -1)
			return (-1);
		else
			len++;
	}
	va_end(ap);
	return ((int)len);
}
