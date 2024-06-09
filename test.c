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
//	void	*ptr = &c;
//	int	len;
//	int	len_origin;
//	len = ft_printf("%x %c  %s   %X    %s      %u %p\n", num, c, str, num, NULL, unum, ptr);
//	len_origin = printf("%x %c  %s   %X    %s      %u %p\n", num, c, str, num, NULL, unum, ptr);
//	ft_printf("ft_printf = %d\nprintf = %d\n", len, len_origin);
//	return (0);
//}

//int	main(void)
//{
//	int n = -1;
//	int	len = 0;
//	ft_printf("%X\n", n);
//	printf("%X\n", n);
//	printf("%p\n", &n);
//	return (0);
//}

//int	main(void)
//{
//	unsigned char	byte = 0x1D;
//	char	hex_digits[] = "0123456789ABCDEF";
//    putchar(hex_digits[(byte >> 4) & 0xF]); // 上位4ビットを表示
//    putchar(hex_digits[byte & 0xF]);       // 下位4ビットを表示
//	return (0);
//}

int main(void)
{
	long n = LONG_MIN;
	unsigned long long ulln = (unsigned long long)(-(n + 1)) + 1;
	ft_putendl_fd(ft_ulltoa_base(ulln, "0123456789"), 1);
	return (0);
}

