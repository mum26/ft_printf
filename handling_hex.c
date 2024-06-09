/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:07:02 by sishige           #+#    #+#             */
/*   Updated: 2024/06/09 16:50:48 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long long ulln, int is_upper)
{
	char	*hex_digits;
	char	*str;
	int		len;

	if (is_upper)
		hex_digits = HEX_DIGITS_UP;
	else
		hex_digits = HEX_DIGITS_LOW;
	str = ft_ulltoa_base(ulln, hex_digits);
	ft_putstr_fd(str, PRINT_FD);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	print_add(unsigned long long ull)
{
	int	len;

	len = write(PRINT_FD, "0x", 2);
	len += print_hex(ull, 0);
	return (len);
}
