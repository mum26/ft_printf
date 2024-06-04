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

//int	main(void)
//{
//	int	num = -1234567890;
//	unsigned int unum = 2147483648;
//	char str[] = "hellllo";
//	char	c = 'X';
//	int	len;
//	int	len_origin;
//	len = ft_printf("%d %c  %s   %i    %s      %u\n", num, c, str, num, NULL, unum);
//	len_origin = printf("%d %c  %s   %i    %s      %u\n", num, c, str, num, NULL, unum);
//	ft_printf("ft_printf = %d\nprintf = %d\n", len, len_origin);
//	return (0);
//}

int	main(void)
{
	printf("%X", -1);
	return (0);
}
