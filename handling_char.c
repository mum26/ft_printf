/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:55:09 by sishige           #+#    #+#             */
/*   Updated: 2024/06/09 16:48:03 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(PRINT_FD, &c, 1));
}

int	print_str(char *str)
{
	if (!str)
		return (write(PRINT_FD, "(null)", 6));
	return (write(PRINT_FD, str, ft_strlen(str)));
}
