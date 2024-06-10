/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:06:31 by sishige           #+#    #+#             */
/*   Updated: 2024/06/10 18:08:10 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int		len;
	char	*str;

	str = ft_lltoa_base((long long)n, DEC_DIGITS);
	if (!str)
		return (0);
	len = ft_strlen(str);
	ft_putstr_fd(str, PRINT_FD);
	free(str);
	return (len);
}

int	print_u_int(unsigned int un)
{
	int		len;
	char	*str;

	str = ft_ulltoa_base((unsigned long long)un, DEC_DIGITS);
	if (!str)
		return (0);
	ft_putstr_fd(str, PRINT_FD);
	len = ft_strlen(str);
	free(str);
	return (len);
}
