/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:07:02 by sishige           #+#    #+#             */
/*   Updated: 2024/06/10 19:32:57 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int fd, unsigned long long ulln, int is_upper)
{
	char	*str;
	int		len;

	if (is_upper)
		str = ft_ulltoa_base(ulln, HEX_DIGITS_UP);
	else
		str = ft_ulltoa_base(ulln, HEX_DIGITS_LOW);
	if (!str)
		return (-1);
	len = write(fd, str, ft_strlen(str));
	free(str);
	return (len);
}

int	print_add(int fd, unsigned long long ulln)
{
	char	*str;
	char	*tmp;
	int		len;

	tmp = ft_ulltoa_base(ulln, HEX_DIGITS_LOW);
	if (!tmp)
		return (-1);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	if (!str)
		return (-1);
	len = write(fd, str, ft_strlen(str));
	free(str);
	return (len);
}
