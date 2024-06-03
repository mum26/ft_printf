/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:56:10 by sishige           #+#    #+#             */
/*   Updated: 2024/06/03 21:26:52 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list ap, int is_upper)
{
	int		val;
	char	*hex;

	if (is_upper)
		hex = "0123456789ABCDEF";
	hex = "0123456789abcdef";
	val = va_arg(ap, int);
	ft_putnbr_fd(val, PRINT_FD);
	return (ft_get_int_digit_cnt(val));
}

int	print_add(va_list ap)
{
	int	val;

	val = va_arg(ap, int);
	ft_putnbr_fd(val, PRINT_FD);
	if (val < 0)
		return (ft_get_int_digit_cnt(val) + 1);
	return (ft_get_int_digit_cnt(val));
}
