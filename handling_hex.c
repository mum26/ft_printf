/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:07:02 by sishige           #+#    #+#             */
/*   Updated: 2024/06/06 21:27:18 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long ull, int is_upper)
{
	char			*hex_digits;
	int				len;
	char			*hex;
	int				ret;

	if (is_upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (!ull)
		return (write(PRINT_FD, "0", 1));
	len = ft_get_cnt_hex_digit(ull);
	ret = len;
	hex = (char *)calloc(len + 1, sizeof(char));
	while (0 < ull)
	{
		hex[--len] = hex_digits[ull % 16];
		ull /= 16;
	}
	ft_putstr_fd(hex, PRINT_FD);
	return (ret);
}

int	print_add(unsigned long long ull)
{
	int	ret;

	ret = write(PRINT_FD, "0x", 2);
	ret += print_hex(ull, 0);
	return (ret);
}
