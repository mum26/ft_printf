/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:42:06 by sishige           #+#    #+#             */
/*   Updated: 2024/05/28 20:03:46 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define PRINT_FD STDOUT_FILENO

typedef int (*put_t)(va_list *);

typedef struct s_specifier
{
	char	specifier;
	put_t	func;
}			t_specifier;

int	ft_isspecifier(int c);
int	ft_printf(char const *fmt, ...);

#endif
