/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:09:29 by sishige           #+#    #+#             */
/*   Updated: 2024/06/07 18:23:06 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_specifier(va_list ap, int c)
{
	if (c == 'c')
		return (print_char(ap));
	else if (c == 's')
		return (print_str(ap));
	else if (c == 'd' || c == 'i')
		return (print_int(ap));
	else if (c == 'u')
		return(print_u_int(ap));
	else if (c == 'x' || c == 'X')
		return(print_hex((unsigned int)va_arg(ap, int), ft_isupper(c)));
	else if (c == 'p')
		return(print_add(va_arg(ap, unsigned long long)));
	else if (c == '%')
		return (write(PRINT_FD, "%", 1));
	return (0);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt++ == '%')
			len += convert_specifier(ap, *fmt++);
		else
			len += write(PRINT_FD, fmt - 1, 1);
	}
	va_end(ap);
	return ((int)len);
}
