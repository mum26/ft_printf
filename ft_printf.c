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

int	convert_specifier(int fd, va_list ap, int c)
{
	if (c == 'c')
		return (print_char(fd, va_arg(ap, int)));
	else if (c == 's')
		return (print_str(fd, va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (print_int(fd, va_arg(ap, int)));
	else if (c == 'u')
		return (print_u_int(fd, va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(fd, (unsigned int)va_arg(ap, int), ft_isupper(c)));
	else if (c == 'p')
		return (print_add(fd, va_arg(ap, unsigned long long)));
	else if (c == '%')
		return (write(fd, "%", 1));
	return (write(fd, &c, 1));
}

int	ft_fileno(FILE *fp)
{
	if (!fp)
		return (-1);
	return (fp->_file);
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
			tmp = convert_specifier(STDIN_FILENO, ap, *fmt++);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else if (write(STDIN_FILENO, fmt - 1, 1) == -1)
			return (-1);
		else
			len++;
	}
	va_end(ap);
	return ((int)len);
}
