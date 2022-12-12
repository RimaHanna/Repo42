/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_hex_putnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:24 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/10 11:30:06 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_x_putchar(char c)
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

static int	ft_size(unsigned int nb)
{
	int	size;

	size = 0;
	while (nb / 16 != 0)
	{
		size++;
		nb = nb / 16;
	}
	size++;
	return (size);
}

int	ft_min_hex_putnbr(unsigned int n)
{
	int	print_len;

	print_len = ft_size(n);
	if (n >= 16)
	{
		ft_min_hex_putnbr(n / 16);
	}
	ft_x_putchar (n % 16);
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
