#include <stdio.h>
#include <stdarg.h>

//void print_numbers(int count, ...) {
//    va_list args;
//    va_start(args, count);
//
//    for (int i = 0; i < count; i++) {
//        int number = va_arg(args, int);
//        printf("%d\n", number);
//    }
//
//    va_end(args);
//}
//
//int main() {
//    print_numbers(8, 10, 20, 30, 8, 9, 10, 114, 514);
//    return 0;
//}

#include "ft_printf.h"

int	main(void)
{
	int	num = -1234567890;
//	char str[] = "hellllo";
	char	c = 'X';
	int	len;
	int	len_origin;
	len = ft_printf("%c  %i  %s  \n", c, num, NULL);
	len_origin = printf("%c  %i  %s  \n", c, num, NULL);
	ft_printf("ft_printf = %d\nprintf = %d\n", len, len_origin);
	return (0);
}
