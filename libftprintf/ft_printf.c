
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
/*	else if (format == 'p')
		printf_len +=  */
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u') // il ne prend pas des negatifs
		print_len += ft_unsigned_putnbr(va_arg(args, int));
	else if (format == '%')
		print_len += ft_putchar('%');

	return (print_len);
}


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;
	
	i = 0;
	print_len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
 /* we are not using in place of args the va_arg(args)
 *  because we don't know the type of the argumens so 
 *  it will be all mixed */ 
			print_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

int main()
{
 
	int i = ft_printf("%u", -2147483648);
	printf("the value of i is: %d\n", i);

/*	int j = printf("%u\n", -2147483648);
	printf("the value of printf is %d\n", j);*/
	return 0;
}

