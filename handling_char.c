/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:55:09 by sishige           #+#    #+#             */
/*   Updated: 2024/06/04 20:07:20 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	int	val;

	val = va_arg(ap, int);
	ft_putchar_fd(val, PRINT_FD);
	return (1);
}

int	print_str(va_list ap)
{
	char	*val;

	val = va_arg(ap, char *);
	if (!val)
		return (write(PRINT_FD, "(null)", 6));
	ft_putstr_fd(val, PRINT_FD);
	return (ft_strlen(val));
}
