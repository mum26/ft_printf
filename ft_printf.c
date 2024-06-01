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

//int	ft_isspecifier(int c)
//{
//	size_t len;
//
//	len = 0;
//	if (c == 'c')
//		len = print_char(ap, int);
//	else if (c == 's')
//		len = print_str(ap, char *);
//	else if (c == 'p')
//		len = printf_();
//	else if (c == 'd')
//		len = printf_int(ap, int);
//	else if (c == 'i')
//		len = printf_int(ap, int);
//	else if (c == 'u')
//		len = print_
//	else if (c == 'x')
//		len = print_
//	else if (c == 'X')
//		len = print_
//	else if (c == '%')
//		len = write(PRINT_FD, '%', 1);
//	return (len);
//}

static int	print_int(va_list *ap)
{
	int	val;

	val = va_arg(*ap, int);
	ft_putnbr_fd(val, PRINT_FD);
	if (val < 0)
		return (ft_get_int_digit_cnt(val) + 1);
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
		if (INT_MAX <= fi)
		{
			len += write(PRINT_FD, fmt, fi);
			fmt += fi;
			fi = 0;
		}
		if (fmt[fi++] != '%')
			continue;
		len += write(PRINT_FD, fmt, fi - 1);
		fmt += fi;
		fi = 0;
		si = 0;
		while (specifiers[si].func != NULL)
		{
			if (specifiers[si].specifier == *fmt)
			{
				len += specifiers[si].func(&ap);
				fmt++;
				break;
			}
			si++;
		}
	}
	va_end(ap);
	if (fi)
		len += write(PRINT_FD, fmt, fi);
	return ((int)len);
}
