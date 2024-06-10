/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:06:31 by sishige           #+#    #+#             */
/*   Updated: 2024/06/10 19:12:42 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int		len;
	char	*str;

	str = ft_lltoa_base((long long)n, DEC_DIGITS);
	if (!str)
		return (-1);
	len = write(PRINT_FD, str, ft_strlen(str));
	free(str);
	return (len);
}

int	print_u_int(unsigned int un)
{
	int		len;
	char	*str;

	str = ft_ulltoa_base((unsigned long long)un, DEC_DIGITS);
	if (!str)
		return (-1);
	len = write(PRINT_FD, str, ft_strlen(str));
	free(str);
	return (len);
}
