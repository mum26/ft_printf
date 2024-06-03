/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:42:06 by sishige           #+#    #+#             */
/*   Updated: 2024/06/03 20:06:36 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define PRINT_FD STDOUT_FILENO

int	ft_printf(char const *fmt, ...);

/* handring_char */
int	print_char(va_list ap);
int	print_str(va_list ap);

/* handring_dec */
int	print_int(va_list ap);
int	print_u_int(va_list ap);

/* handring_hex */
int	print_hex(va_list ap, int is_upper);
int	print_add(va_list ap);
#endif
