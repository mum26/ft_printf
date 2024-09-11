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

int	ft_fprintf(FILE *fp, char const *fmt, ...)
{
	va_list	ap;
	int		len;
	int		tmp;
	int		fd;

	fd = ft_fileno(fp);
	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt++ == '%')
		{
			tmp = convert_specifier(fd, ap, *fmt++);
			if (tmp == -1)
				return (-1);
			len += tmp;
		}
		else if (write(fd, fmt - 1, 1) == -1)
			return (-1);
		else
			len++;
	}
	va_end(ap);
	return ((int)len);
}
