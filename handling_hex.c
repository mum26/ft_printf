/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:07:02 by sishige           #+#    #+#             */
/*   Updated: 2024/06/04 21:00:31 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(va_list ap, int is_upper)
{
	int		val;
	char	*hex_digitis;
	int		len;

	if (is_upper)
		hexi_digits = "0123456789ABCDEF";
	hex_digits = "0123456789abcdef";
	val = va_arg(ap, int);
	while (0 < val)
	{
		write(PRINT_FD, hex_digits[])
	}
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
