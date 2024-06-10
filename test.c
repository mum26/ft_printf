#include "ft_printf.h"
#include <stdio.h>
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

int	main(void)
{
	int n = INT_MIN;
	ft_printf("ft_printf: %X\n", n);
	printf("printf: %X\n", n);
	ft_printf("ft_printf: %p\n", &n);
	printf("printf: %p\n", &n);
	return (0);
}
