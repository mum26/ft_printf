/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:42:06 by sishige           #+#    #+#             */
/*   Updated: 2024/06/09 17:52:02 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define PRINT_FD STDOUT_FILENO

int	ft_printf(char const *fmt, ...);

/* handring_char */
int	print_char(int c);
int	print_str(char *str);

/* handring_dec */
int	print_int(int n);
int	print_u_int(unsigned int un);

/* handring_hex */
int	print_hex(unsigned long long ulln, int is_upper);
int	print_add(unsigned long long ulln);
#endif
