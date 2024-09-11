/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <sishige@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:34:03 by sishige           #+#    #+#             */
/*   Updated: 2024/06/10 19:34:27 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define PRINT_FD STDOUT_FILENO

int	ft_printf(char const *fmt, ...);
int	ft_fprintf(FILE *fp, char const *fmt, ...);
int	convert_specifier(int fd, va_list ap, int c);
int	ft_fileno(FILE *fp);

/* handring_char */
int	print_char(int fd, int c);
int	print_str(int fd, char *str);

/* handring_dec */
int	print_int(int fd, int n);
int	print_u_int(int fd, unsigned int un);

/* handring_hex */
int	print_hex(int fd, unsigned long long ulln, int is_upper);
int	print_add(int fd, unsigned long long ulln);
#endif
