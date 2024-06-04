/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:06:31 by sishige           #+#    #+#             */
/*   Updated: 2024/06/04 20:06:46 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list ap)
{
	int	val;

	val = va_arg(ap, int);
	ft_putnbr_fd(val, PRINT_FD);
	if (val < 0)
		return (ft_get_int_digit_cnt(val) + 1);
	return (ft_get_int_digit_cnt(val));
}

int	print_u_int(va_list ap)
{
	unsigned int	val;

	val = va_arg(ap, unsigned int);
	ft_put_unbr_fd(val, PRINT_FD);
	return (ft_get_uint_digit_cnt(val));
}
