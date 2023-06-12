/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:46:32 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/10 11:38:33 by rhanna           ###   ########.fr       */
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
	else if (format == 'u')
		print_len += ft_unsigned_putnbr(va_arg(args, int));
	else if (format == '%')
		print_len += ft_putchar('%');
	else if (format == 'x')
		print_len += ft_min_hex_putnbr(va_arg(args, int));
	else if (format == 'X')
		print_len += ft_max_hex_putnbr(va_arg(args, int));
	else if (format == 'p')
		print_len += ft_pointer(va_arg(args, unsigned long long int));
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

/*
int main()
{
	int i = ft_printf(" %p %p ", 0, 0);
	printf("the value of i is: %d\n", i);

	int j = printf(" %p %p ", 0, 0);
	printf("the value of printf is %d\n", j);
	return 0;
}
*/

/* if we weren't using recursif fonctions in putnbr
and unsigned putnbr we would have to put the same type
of those fonction in the formats here, but since we are 
using the recursivity we keep the type int */
