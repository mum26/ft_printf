/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:09:29 by sishige           #+#    #+#             */
/*   Updated: 2024/05/28 21:00:34 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isspecifier(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c ==  'd' || c == 'i'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
			return (1);
	return (0);
}

static int	print_int(va_list *ap)
{
	int	val;

	val = va_arg(*ap, int);
	ft_putnbr_fd(val, PRINT_FD);
	return (ft_get_int_digit_cnt(val));
}

static int	print_str(va_list *ap)
{
	char	*val;

	val = va_arg(*ap, char *);
	ft_putstr_fd(val, PRINT_FD);
	return (ft_strlen(val));
}

static int	print_char(va_list	*ap)
{
	int	val = va_arg(*ap, int);
	ft_putchar_fd(val, PRINT_FD);
	return (1);
}

t_specifier specifiers[] = {
    {'d', print_int},
    {'s', print_str},
    {'c', print_char},
    {0, NULL}
};

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	len;
	size_t	fi;
	size_t	si;

	va_start(ap, fmt);
	len = 0;
	fi = 0;
	while (fmt[fi])
	{
		if (fmt[fi] == '%' || INT_MAX <= fi)
		{
			if (0 < fi)
				write(PRINT_FD, fmt, fi - 1);
			fmt += fi + 1;
			len += fi;
			fi = 0;
			si = 0;
			while (specifiers[si].func != NULL)
			{
				if (specifiers[si].specifier == *fmt)
				{
					len = specifiers[si].func(&ap);
					fmt++;
					break;
				}
				si++;
			}
		}
		else
			fi++;
	}
	va_end(ap);
	ft_putstr_fd((char *)fmt, PRINT_FD);
	return ((int)(len + fi));
}
