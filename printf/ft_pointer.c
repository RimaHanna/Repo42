/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_hex_putnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:24 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/05 18:02:24 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void ft_x_putchar(char c)
{
	if (c == 10)
		write(1, "a", 1);
	else if (c == 11)
		write(1, "b", 1);
	else if (c == 12)
		write(1, "c", 1);
	else if (c == 13)
		write(1, "d", 1);
	else if (c == 14)
		write(1, "e", 1);
	else if (c == 15)
		write(1, "f", 1);
	else
	{
		c = c + '0';
		write(1, &c, 1);
	}
}

static int      ft_size(unsigned long long int nb)
{
        long long int     size;

        size = 0;
        while (nb / 16 != 0)
        {
                size++;
                nb = nb / 16;
        }
        size++;
        return (size);
}


static void ft_min_x_putnbr(unsigned long long int n)
{

        if (n >= 16)
        {
                ft_min_x_putnbr(n / 16);
        }
        ft_x_putchar (n % 16);
}

int	ft_pointer(unsigned long long int p)
{
	int print_len;

	print_len = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		print_len = 5;
		return (print_len);
	}
	write(1, "0x", 2);
	print_len = 2;
	if (p == 0)
	{
		write(1, "0", 1);
		print_len++;
	}
	else
	{
		ft_min_x_putnbr(p);
		print_len += ft_size(p);
	}
	return (print_len);
}


/*
int main()
{
	int ret = ft_min_hex_putnbr(-2147483648);
	printf("\nret = %d\n", ret);

	int i = printf("%x", -2147483648);
	printf("\ni = %i", i);

	return 0;
}
*/
