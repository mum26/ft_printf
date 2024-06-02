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

int	print_str(va_list *ap)
{
	char	*val;

	val = va_arg(*ap, char *);
	ft_putstr_fd(val, PRINT_FD);
	return (ft_strlen(val));
}

int	print_char(va_list	*ap)
{
	int	val = va_arg(*ap, int);
	ft_putchar_fd(val, PRINT_FD);
	return (1);
}