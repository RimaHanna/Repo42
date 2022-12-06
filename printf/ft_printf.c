/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:46:32 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/05 18:04:50 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u') // il ne prend pas des negatifs
		print_len += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (format == '%')
		print_len += ft_putchar('%');
	else if(format == 'x')
		print_len += ft_min_hex_putnbr(va_arg(args, unsigned int));

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
 
	int i = ft_printf("%x\n", 123);
	printf("the value of i is: %d\n", i);

	int j = printf("%x\n", 123);
	printf("the value of printf is %d\n", j);
	return 0;
}
