/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:49:34 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/05 17:50:12 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_size(int nb)
{
	int	size;

	size = 1;
	while (nb / 10 != 0)
	{
		size = size * 10;
		nb = nb / 10;
	}
	return (size);
}

int	int_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbr(int n)
{
	int	div;
	int	print_size;

	print_size = 0;
	if (n == -2147483648)
		return (int_min());
	if (n < 0)
	{
		print_size++;
		ft_putchar('-');
		n = -n;
	}
	div = ft_size(n);
	while (div / 10 != 0)
	{
		print_size++;
		ft_putchar((n / div) + '0');
		n = n % div;
		div = div / 10;
	}
	print_size++;
	ft_putchar(n + '0');
	return (print_size);
}
