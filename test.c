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

#include "libftprintf.h"

int	main(void)
{
	int	num = 1234567890;
	char str[] = "hellllo";
	int	len;
	int	len_origin;
	len = ft_printf("  %d  %s  \n", num, str);
	len_origin = printf("  %d  %s  \n", num, str);
	ft_printf("len = %d\nlen_origin = %d\n", len, len_origin);
	return (0);
}
